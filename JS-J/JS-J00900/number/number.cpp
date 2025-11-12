#include <bits/stdc++.h>
using namespace std;

int num[10];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    char ch;
    while (cin >> ch)
    {
        if ('0' <= ch && ch <= '9')
            num[ch - '0'] += 1;
    }
    for (int i = 9; i >= 0; i--)
        for (int j = 1; j <= num[i]; j++)
            putchar(i + '0');
    return 0;
}
