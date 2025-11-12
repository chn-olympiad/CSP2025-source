#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
const int M = 998244353;
int a[N];
int vis[N];
int n;
long long ans;
long long dp[N][N];
void dfs(int dep, long long he, int mx, int last)
{
    if (he > mx * 2)
    {
        ++ans;
    }
    if (dep == n) return ;
    for (int i = last + 1; i <= n; ++i)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            dfs(dep + 1, he + a[i], max(mx, a[i]), i);
            vis[i] = 0;
        }
    }
}
void init(){
for (int i = 1; i <= N - 10; ++i)
{
    dp[i][0] = 1;
    for (int j = 1; j <= i;++j)
    {
        dp[i][j] = max(dp[i][i - j] , dp[i - 1][j] + dp[i - 1][j - 1]);
        dp[i][j] %= M;
    }
}
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    int flag = 1;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] != 1) flag = 0;
    }
    if (flag == 1)
    {
        init();
        long long ans = 0;
        for (int i = 3; i <= n; ++i)
        {
            ans += dp[n][i];
            ans %= M;
        }
        cout << ans;
    }
    else{
    dfs(0, 0, 0, 0);
    cout << ans % M;
    }
    return 0;
}
