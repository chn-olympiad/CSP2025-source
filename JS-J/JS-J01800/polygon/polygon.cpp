#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll mod = 998244353;
ll a[5005], n, dp[25][105][2005][5], dp1[5005][5005];
ll dfs(ll x, ll m, ll s, ll x1){
    if (x == n + 1){
        if (s > m * 2 && x1 >= 3) return 1;
        return 0;
    }
    if (dp[x][m][s][x1] != -1) return dp[x][m][s][x1];
    return dp[x][m][s][x1] = (dfs(x + 1, max(m, a[x]), s + a[x], min(3ll, x1 + 1)) + dfs(x + 1, m, s, x1)) % mod;
}
ll dfs1(ll x, ll num){
    if (x == n + 1){
        if (num >= 3) return 1;
        return 0;
    }
    if (dp1[x][num] != -1) return dp1[x][num];
    return dp1[x][num] = (dfs1(x + 1, num) + dfs1(x + 1, num + 1)) % mod;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    bool f = 1;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] != 1) f = 0;
    }
    memset(dp, -1, sizeof(dp));
    memset(dp1, -1, sizeof(dp1));
    if (f){
        cout << dfs1(1, 0);
        return 0;
    }
    cout << dfs(1, 0, 0, 0) % mod;
    return 0;
}
