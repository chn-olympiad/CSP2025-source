#include <bits/stdc++.h>
// #define int long long
#define loop(i, a, b) for(int i = (a) ; i <= (int)(b) ; i++)
#define rloop(i, a, b) for(int i = (b) ; i >= (int)(a) ; i--)
#define chkmin(a, b) (a = min(a, b))
#define chkmax(a, b) (a = max(a, b))
using namespace std;
const int N = 5e3 + 5;
const int A = 1e4 + 5;
const int mod = 998244353;
int n, a[N], dp[N][A];
void solve() {
    cin >> n;
    loop(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    dp[0][0] = 1;
    loop(i, 1, n) loop(j, 0, A - 1) {
        dp[i][j] = dp[i - 1][j];
        if(j >= a[i]) (dp[i][j] += dp[i - 1][j - a[i]]) %= mod;
    }
    int ans = 1;
    loop(i, 1, n) (ans *= 2) %= mod;
    loop(i, 1, n) loop(j, a[i], a[i] * 2) (ans += mod - (dp[i][j] - dp[i - 1][j] + mod) % mod) %= mod;
    (ans += mod - 1) %= mod;
    cout << ans << '\n';
}
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}