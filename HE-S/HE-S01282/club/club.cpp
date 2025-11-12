#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

inline int read()
{
    int f = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return f * x;
}

const int NR = 1e5 + 10;
int a[NR][5];
int b[5][NR];
int sz[NR];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T = read();
    while (T --)
    {
        int n = read();
        sz[1] = sz[2] = sz[3] = 0;
        int ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= 3; j ++)
            {
                a[i][j] = read();
            }
            if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
            {
                b[1][++sz[1]] = a[i][1] - max(a[i][2], a[i][3]);
            }
            else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
            {
                b[2][++sz[2]] = a[i][2] - max(a[i][1], a[i][3]);
            }
            else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2])
            {
                b[3][++sz[3]] = a[i][3] - max(a[i][1], a[i][2]);
            }
            ans += max(max(a[i][1], a[i][2]), a[i][3]);
        }
        for (int j = 1; j <= 3; j ++)
        {
            if (sz[j] > n / 2)
            {
                sort(b[j] + 1, b[j] + sz[j] + 1);
                for (int i = 1; i <= sz[j] - (n / 2); i ++)
                {
                    ans -= b[j][i];
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
