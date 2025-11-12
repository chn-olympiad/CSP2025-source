#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5, M = 35, P = 20, Q = 205, R = 105;
int a[N][3], n, t, ans, speA, speB, dp[P][M][M][M], dp2[Q][R][R];
void dfs(int sum, int cnta, int cntb, int cntc, int i)
{
    if (i > n)
    {
        if (cnta <= n / 2 && cntb <= n / 2 && cntc <= n / 2) ans = max(ans, sum);
        return;
    }
    dfs(sum + a[i][1], cnta + 1, cntb, cntc, i + 1);
    dfs(sum + a[i][2], cnta, cntb + 1, cntc, i + 1);
    dfs(sum + a[i][3], cnta, cntb, cntc + 1, i + 1);
}
priority_queue<int> q;
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        ans = 0, speA = speB = 1;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if (a[i][2] != 0) speA = 0;
            if (a[i][3] != 0) speB = 0;
        }
        if (n <= 10)
        {
            dfs(0, 0, 0, 0, 1);
            cout << ans << endl;
        }
        else if (speA)
        {
            for (int i = 1; i <= n; i++) q.push(a[i][1]);
            for (int i = 1; i <= n / 2; i++)
            {
                ans += q.top();
                q.pop();
            }
            cout << ans << endl;
        }
        else if (speB)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= n / 2; j++)
                {
                    for (int k = 0; k <= n / 2; k++)
                    {
                        int p = (j > 0 ? dp2[i - 1][j - 1][k] + a[i][1] : 0);
                        int q = (k > 0 ? dp2[i - 1][j][k - 1] + a[i][2] : 0);
                        dp2[i][j][k] = max(p, q);
                    }
                }
            }
            for (int i = 0; i <= n / 2; i++)
            {
                for (int j = 0; j <= n / 2; j++) ans = max(ans, dp2[n][i][j]);
            }
            cout << ans << endl;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= n / 2; j++)
                {
                    for (int k = 0; k <= n / 2; k++)
                    {
                        for (int l = 0; l <= n / 2; l++)
                        {
                            int p = (j > 0 ? dp[i - 1][j - 1][k][l] + a[i][1] : 0);
                            int q = (k > 0 ? dp[i - 1][j][k - 1][l] + a[i][2] : 0);
                            int r = (l > 0 ? dp[i - 1][j][k][l - 1] + a[i][3] : 0);
                            dp[i][j][k][l] = max({p, q, r});
                        }
                    }
                }
            }
            for (int i = 0; i <= n / 2; i++)
            {
                for (int j = 0; j <= n / 2; j++)
                {
                    for (int k = 0; k <= n / 2; k++) ans = max(ans, dp[n][i][j][k]);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
