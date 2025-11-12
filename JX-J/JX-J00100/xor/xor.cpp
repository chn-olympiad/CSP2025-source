#include <bits/stdc++.h>
using namespace std;
const int W = 1048580;
const int N = 5e5 + 5;
int n, k;
int val[W];
int a[N], s[N];
int dp[N];
bool vis[W];
signed main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = (s[i - 1] ^ a[i]);
    }
    int mx = 0;
    vis[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = mx;
        if (vis[(s[i] ^ k)])dp[i] = max(dp[i], val[(s[i] ^ k)] + 1);
        mx = max(mx, dp[i]);
        val[s[i]] = max(val[s[i]], dp[i]);
        vis[s[i]] = 1;
    }
    cout << dp[n] << '\n';
    return 0;
}
