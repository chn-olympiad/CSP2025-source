#include <stdio.h>
#include <vector>

constexpr int FACT[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

char s[11];
int count, failed, i, j, m, n, value, c[10], now[10];
std::vector<int> numbers;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    scanf("%d%d%s", &n, &m, s);
    if (n > 10)
    {
        putchar(48);
        return 0;
    }
    for (i = 0; i < n; ++i)
        scanf("%d", c + i);
    for (i = 0; i < FACT[n]; ++i)
    {
        value = i;
        for (j = 0; j < n; ++j)
            numbers.push_back(c[j]);
        for (j = n - 1; j >= 0; --j)
        {
            now[n - j - 1] = numbers[value / FACT[j]];
            numbers.erase(numbers.begin() + value / FACT[j]);
            value %= FACT[j];
        }
        for (j = 0; j < n; ++j)
            if (failed >= now[j] || s[j] == '0')
                ++failed;
        count += failed <= n - m;
        failed = 0;
    }
    printf("%d", count);

    return 0;
}
