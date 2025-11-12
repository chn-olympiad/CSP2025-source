#include <bits/stdc++.h>
using namespace std;

const int N = 10005, mod = 998244353;
int a [N], f [2][N], C [N][N];

int main ()
{
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    int n, m = 0;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", a + i);
        m = std::max (m, a [i]);
    }
    f [0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= 2 * m; k++)
        {
            f [i & 1][k] = f [i - 1 & 1][k];
            if (k >= a [i])
            {
                f [i & 1][k] = (f [i & 1][k] + f [i - 1 & 1][k - a [i]]) % mod;
            }
        }
    }
    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    for (int i = 0; i <= n; i++)
    {
        C [i][0] = C [i][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            C [i][j] = (C [i - 1][j] + C [i - 1][j - 1]) % mod;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans1 = (ans1 + C [n][i]) % mod;
    }
    for (int i = 1; i <= 2 * m; i++)
    {
        ans2 = (ans2 + f [n & 1][i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a [i] + a [j] <= 2 * max (a [i], a [j]))
            {
                ans3++;
            }
        }
    }
    printf ("%d\n", ((ans1 - ans2 + 1) % mod + mod) % mod);
    return 0;
}