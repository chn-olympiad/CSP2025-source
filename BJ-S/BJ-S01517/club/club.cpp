#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int t;
int n;
int a[100010][4];
int b[100010];
int f[2][210][210][210];

bool cmp(int x, int y)
{
    return x > y;
}

void work2()
{
    for (int i = 1; i <= n; ++i)
        b[i] = a[i][1];
    sort(b + 1, b +n + 1, cmp);
    int s = 0;
    for (int i = 1; i <= n / 2; ++i)
        s += b[i];
    cout << s << '\n';
    return ;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >>t;
    while (t--)
    {
        cin >>n;
        bool flg = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= 3; ++j)
                cin >>a[i][j];
            if (a[i][2] != 0 || a[i][3] != 0)
                flg = 0;
        }
        if (flg && n >= 1000)
        {
            work2();
            continue;
        }
        int ans = 0;
        for (int p = 1; p <= n; ++p)
            for (int i = 0; i <= min(p, n / 2); ++i)
                for (int j = 0; j <= min(p - i, n / 2); ++j)
                {
                    int k = p - i - j;
                    if (k > n / 2)
                        continue;
                    f[p & 1][i][j][k] = max({(i == 0 ? 0 : f[p - 1 & 1][i - 1][j][k] + a[p][1]),
                                        (j == 0 ? 0 : f[p - 1 & 1][i][j - 1][k] + a[p][2]),
                                        (k == 0 ? 0 : f[p - 1 & 1][i][j][k - 1] + a[p][3]) });
                    if (p == n)
                        ans = max(ans, f[p & 1][i][j][k]);
                }
        cout << ans << '\n';
    }
    return 0;
}
