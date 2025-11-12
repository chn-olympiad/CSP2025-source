#include <bits/stdc++.h>
#define int long long
using namespace std;
const int P = 998244353;
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, ans = 0, q = 1;
    cin >> n;
    vector<int> v(n), dp(5001);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int t = q;
        for (int j = 0; j <= v[i]; j++) {
            t -= dp[j];
            if (t < 0) t += P;
        }
        ans += t;
        ans %= P;
        for (int j = 5000; j >= v[i]; j--) (dp[j] += dp[j - v[i]]) %= P;
        q *= 2;
        q %= P;
    }
    cout << ans % P << '\n';
    return 0;
}