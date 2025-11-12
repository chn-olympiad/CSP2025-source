#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, c[505], dp[1 << 19][20];
char mp[505];
void add(int &x, int y) { (x += y) >= mod && (x -= mod); }
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> mp;
    if (n <= 18)
    {
        for (int i = 0; i < n; i++)
            cin >> c[i];
        dp[0][0] = 1;
        for (int i = 0; i < (1 << n) - 1; i++)
            for (int j = 0; j < n; j++)
                if (!(i >> j & 1))
                {
                    int now = __builtin_popcount(i);
                    int to = i | (1 << j);
                    for (int k = 0; k <= n; k++)
                    {
                        if (k < c[j] && mp[now] == '1')
                            add(dp[to][k], dp[i][k]);
                        else add(dp[to][k + 1], dp[i][k]);
                    }
                }
        int ans = 0;
        for (int i = 0; i <= n - m; i++)
            add(ans, dp[(1 << n) - 1][i]);
        cout << ans;
    }
    else
    {
        int ans = 1;
        for (int i = 1; i <= n; i++)
            ans = 1ll * ans * i % mod;
        cout << ans << '\n';
    }
    return 0;
}