#include <bits/stdc++.h>
using namespace std;

int main () {

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 5), dp(n + 5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0, pos = 0;
    vector<int> xors((1 << 20) + 5);
    for (int i = 1; i <= n; i++) {
        if (i > 1) pos ^= a[i];
        dp[i] = dp[i - 1];
        xors[pos ^ a[i]] = max(xors[pos ^ a[i]], i);
        if (xors[pos ^ k]) ans = max(ans, dp[i] = max(dp[i], dp[xors[pos ^ k] - 1] + 1));
    }
    cout << ans;
    return 0;
}
