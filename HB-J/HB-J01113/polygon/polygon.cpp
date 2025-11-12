#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans;
int maxnn;
void solve()
{
    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (j == 1)
                sum[i][j] = i;
            else if (i == j)
                sum[i][j] = 1;
            else
                sum[i][j] = (sum[i - 1][j - 1] + sum[i - 1][j]) % 998244353, sum[i][j] %= 998244353;
        }
    }
    for (int i = 3; i <= n; ++i)
        ans += sum[n][i], ans %= 998244353;
    cout << ans;
}
void dfs(int cnt, int maxn, int pos, int xz)
{
    if (pos == n + 1)
    {
        if (maxn * 2 < cnt && xz >= 3)
        {
            ans++;
            ans %= 998244353;
        }
        return;
    }
    dfs(cnt + a[pos], max(maxn, a[pos]), pos + 1, xz + 1);
    dfs(cnt, maxn, pos + 1, xz);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    if (n >= 100)
    {
        solve();
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i], maxnn = max(maxnn, a[i]);
    dfs(0, 0, 1, 0);
    cout << ans;
    return 0;
}