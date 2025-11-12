#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int N = 5e5 + 5, MAX = 1 << 22;
int n, k, a[N], sum[N], lst[MAX], dp[N];
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    // cin >> n >> k;
    // for (int i = 1; i <= n; i++) cin >> a[i];
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < 20; j++)
    //         if ((a[i] >> j) & 1) lst[i][j] = i;
    //         else lst[i][j] = lst[i - 1][j];
    // }
    // for (int i = 1; i <= n; i++) {
    //     int pre = i;
    //     for (int j = 0; j < 20; j++)
    //         if (((a[i] >> j) & 1) != ((k >> j) & 1)) pre = min(pre, lst[i - 1][j]);
    //     if (pre > 0) dp[i] = max(dp[i - 1], dp[pre - 1] + 1);
    //     else dp[i] = dp[i - 1];
    // }
    // cout << dp[n] << '\n';
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) sum[i] = sum[i + 1] ^ a[i];
    for (int i = 1; i <= n; i++) {
        lst[sum[i]] = i;
        int pre = lst[a[i] ^ sum[i] ^ k];
        if (pre >= 1) dp[i] = max(dp[i - 1], dp[lst[a[i] ^ sum[i] ^ k] - 1] + 1);
        else dp[i] = dp[i - 1];
    }
    cout << dp[n] << '\n';
    return 0;
}
// expect 100pts