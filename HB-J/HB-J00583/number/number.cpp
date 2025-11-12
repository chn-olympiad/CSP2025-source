#include <bits/stdc++.h>

using namespace std;

char c;
int num[10];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    memset(num, 0, sizeof num);
    while (cin >> c)
    {
        if ('0' <= c && c <= '9')
        {
            int c_num = c - '0';
            num[c_num] ++;
        }
    }

    for (int i = 9; i >= 0; i--)
    {
        for (int j = 1; j <= num[i]; j++)
            cout << i;
    }

    return 0;
}
