#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a[5008], f = 1, p = 998244353, dp1[508][50008], dp2[508][50008], s = 0, ans = 0;
void solve1()
{
    int sb = 1;
    for (int i = 1; i <= n; i++)
        sb = sb * 2 % p;
    cout << (sb - n * (n - 1) / 2 - n - 1) % p << endl;
}

void solve2()
{
    if (a[1] + a[2] <= a[3]) cout << 0 << endl;
    else cout << 1 << endl;
}

void solve3()
{
    sort(a + 1, n + a + 1);
    for (int i = 1; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k <= n; k++)
            {
                if (a[k] < a[i] + a[j]) dp1[k][a[i] + a[j] + a[k]] = (dp1[k][a[i] + a[j] + a[k]] + 1) % p;
                else dp2[k][a[i] + a[j] + a[k]] = (dp2[k][a[i] + a[j] + a[k]] + 1) % p;
            }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (i >= 4)
            {
                  if (a[i] * 2 < j)
                  {
                      dp1[i][j] = (dp1[i - 1][j] + dp2[i - 1][j - a[i]] + dp1[i - 1][j - a[i]] + dp1[i][j]) % p;
                      dp2[i][j] = (dp2[i - 1][j] + dp2[i][j]) % p;
                  }
                  else
                  {
                      dp2[i][j] = (dp2[i - 1][j] + dp2[i - 1][j - a[i]] + dp1[i - 1][j - a[i]] + dp2[i][j]) % p;
                      dp1[i][j] = (dp1[i - 1][j] + dp1[i][j]) % p;
                  }
            }

        }
    }
    for (int i = 1; i <= s; i++)
        ans = (ans + dp1[n][i]) % p;
    cout << ans << endl;

}

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
        if (a[i] != 1) f = 0;
    }
    sort(a + 1, n + a + 1);
    if (n == 3) solve2();
    else if (f == 1) solve1();
    else solve3();
    return 0;
}
