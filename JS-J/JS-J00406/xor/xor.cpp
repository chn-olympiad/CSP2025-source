#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> s(n + 1), last(1 << 20, -1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[i] = s[i - 1] ^ x;
    }
    last[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (last[s[i] ^ k] != -1) dp[i] = max(dp[i], dp[last[s[i] ^ k]] + 1);
        last[s[i]] = i;
    }
    cout << dp[n] << '\n';
    return 0;
}