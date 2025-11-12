#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;
int n, a[5005];long long ans; int t[5005];
int dp[1005][1005];
void dfs(int step, int cnt)
{
    if(step == n + 1)
    {
        //for(int i = 1; i <= cnt; i++) cout << t[i] << ' ';
        //cout << endl;
        if(cnt < 3) return ;
        int maxn = -1e9, sum = 0;
        for(int i = 1; i <= cnt; i++) maxn = max(maxn, t[i]), sum += t[i];
        if(sum > maxn * 2) {ans++; ans %= M;}
        return ;
    }
    t[cnt + 1] = a[step];
    dfs(step + 1, cnt + 1);
    t[cnt + 1] = -1;
    dfs(step + 1, cnt);
}

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int maxa = -1e9;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j > i) continue;
            if(j == i) dp[i][j] = 1;
            else if(j == 1) dp[i][j] = i;
            else dp[i][j] = 1ll * dp[i - 1][j] + dp[i - 1][j - 1];
            dp[i][j] %= M;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    if(n <= 20)
    {
        dfs(1, 0);
        cout << ans << endl;
        return 0;
    }
    if(maxa == 1)
    {
        for(int i = 3; i <= n; i++)
        {
            ans += dp[n][i];
            ans %= M;
        }
        cout << ans << endl;
        return 0;
    }
    return 0;
}
