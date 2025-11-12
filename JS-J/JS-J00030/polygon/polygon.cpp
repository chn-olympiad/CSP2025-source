#include <bits/stdc++.h>
#define int long long
int n, a[5005], dp[5005][10005], m = 998244353, sum, ans;
int pow2(int b) {
    if (b == 1)
        return 2;
    if (b % 2)
        return 2 * pow2(b - 1) % m;
    return pow2(b / 2) * pow2(b / 2) % m;
}
signed main() {
    std::freopen("polygon.in", "r", stdin), std::freopen("polygon.out", "w", stdout);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    for (int i = 3; i <= n; ++i) {
        sum = 0, memset(dp, 0, sizeof(dp)), dp[0][0] = 1;
        for (int j = 1; j < i; ++j) {
            for (int k = 0; k <= a[i] - a[j]; ++k)
                dp[j][k + a[j]] += dp[j - 1][k], dp[j][k + a[j]] %= m;
            for (int k = 0; k <= a[i]; ++k)
                dp[j][k] += dp[j - 1][k], dp[j][k] %= m;
        }
        for (int j = 0; j <= a[i] * 2; ++j)
            sum += dp[i - 1][j], sum %= m;
        ans += pow2(i - 1) - sum, ans %= m;
    }
    std::cout << ans;
    return 0;
}
