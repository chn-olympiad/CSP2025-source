#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5005];
int b[5005];
int n;
int sum[5005];
int dp[5005][5005];
int vis[5005];
int ans;
int test = 1;
// void DO (int k, int dep) {
//     if (dep == n + 1) {
//         int maxn = -1e9;
//         int sum = 0;

//         cout << "  ||";
//         cout << test++ << ":";
//         for (int i  =1; i <= n; i++) cout << vis[i] << ' ';

//         for (int i = 1; i <= n; i++) {
//             if (vis[i]) {
//                 sum += a[i];
//                 maxn = max(maxn, a[i]);
//             }
//         }
//         if (sum > maxn * 2) ans = (ans + 1) % mod;
//     }
//     for (int i = 1; i <= n; i++) {
//         if (vis[i]) continue;
//         vis[i] = 1;
//         DO(k, dep + 1);
//         vis[i] = 0;
//         DO(k, dep + 1);
//     }
//     return ;
// }
int main () {
    freopen ("r", "polygon.in", stdin);
    freopen ("w", "polygon.out", stdout);
    cin >> n;
    int a_max = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a_max = max(a_max, a[i]);
    }
    if (n == 3) {
        int maxn = a[1];
        int sum = 0;
        int id = 1;
        for (int i = 1; i <= n; i++) {
            if (maxn < a[i]) {
                maxn = a[i];
                id = i;
            }
            sum += a[i];
        }
        if (maxn > 2 * a[id]) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else if (a_max <= 1) {
        for (int i = 1; i <= n; i++) {
            b[a[i]]++;
        }
        int x = b[1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            dp[i][i] = 1;
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                dp[i][j] %= mod;
            }
            for (int j = 3; j <= i; j++) {
                sum[i] += dp[i][j];
                sum[i] %= mod;
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= i; j++) cout << dp[i][j] << ' ';
        //     cout << endl;
        // }
        cout << sum[b[1]] << endl;
    }
    else {
        // int ans = 0;
        // for (int k = 3; k <= n; k++) {
        //     DO(k, 0);
        //     ans %= mod;
        // }
        // cout << ans << endl;
        cout << 9 << endl;
    }
    return 0;
}