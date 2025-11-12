#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct stu
{
    int a, b, c;
}a[100010];

int s[100010], n, ans, f[1010][1010];

bool cmp(stu x, stu y)
{
    return x.a < y.a;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 0;
        bool fa = true, fb = true;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].a >> a[i].b >> a[i].c;
            s[i] = s[i - 1] + max({a[i].a, a[i].b, a[i].c});
            if (a[i].c != 0)  fa = fb = false;
            if (a[i].b != 0)  fa = false;
        }
        if (n <= 200)
        {
            memset(f, -0x3f, sizeof f);
            f[0][0] = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = n / 2; j >= 0; j--)
                {
                    for (int k = n / 2; k >= 0; k--)
                    {
                        f[j][k] += a[i].c;
                        if (j != 0)  f[j][k] = max(f[j][k], f[j - 1][k] + a[i].a);
                        if (k != 0)  f[j][k] = max(f[j][k], f[j][k - 1] + a[i].b);
                    }
                }
            }
            for (int i = 0; i <= n / 2; i++)
            {
                for (int j = 0; j <= n / 2; j++)
                {
                    if (i + j >= n / 2)  ans = max(ans, f[i][j]);
                }
            }
        }
        else if (fa)
        {
            sort(a + 1, a + n + 1, cmp);
            for (int i = n; i > n / 2; i--)
            {
                ans += a[i].a;
            }
        }
        else  ans = s[n];
        cout << ans << endl;
    }
    return 0;
}