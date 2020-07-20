#include <iostream>
#include <iomanip>
#include <vector>

std::vector<std::vector<int>> vec;

bool is_prime(int n)
{
    if (n < 4)
        return n > 1;
    else if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i < n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}
void print_result()
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int it = 0; it < vec.size(); it++)
        {
            int num = vec[i][it];
            if (is_prime(num))
                std::cout << std::setw(2) << "X";
            else
                std::cout << std::setw(2) << " ";
        }
        std::cout << "\n";
    }
}
std::vector<std::vector<int>> make_spiral(int num_rows)
{
    int first = num_rows * num_rows;
    for (int iterator = 0; iterator < num_rows / 2; iterator++)
    {
        for (int i = 0; i + 2 * iterator < num_rows; i++)
        {
            vec[iterator][i + iterator] = first - 2 * (num_rows - 2 * iterator) + 2;
            vec[num_rows - 1 - iterator][num_rows - i - iterator - 1] = first;
            first--;
        }

        for (int i = 1; i + 2 * iterator < num_rows - 1; i++)
        {
            vec[num_rows - 1 - iterator - i][iterator] = first;

            vec[iterator + i][num_rows - 1 - iterator] = first - 2 * (num_rows - 2 * iterator) + 2;
            first--;
        }
        first -= 2 * (num_rows - 2 * iterator) - 2;
    }

    return vec;
}

void init_vector(int num_rows)
{
    std::vector<int> row(num_rows, 0);
    for (int it = 0; it < num_rows; it++)
        vec.push_back(row);
}

int main()
{
    init_vector(205);
    make_spiral(205);
    print_result();
}
