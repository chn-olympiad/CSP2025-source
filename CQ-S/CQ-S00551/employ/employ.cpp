#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define debug(x) cerr << #x << ' ' << x << '\n'
using LL = long long;
constexpr int MAXN = 505, N = 18, mod = 998244353;
inline void inc(int &x, int y) { (x += y) >= mod && (x -= mod); }
inline void dec(int &x, int y) { (x -= y) < 0 && (x += mod); }
inline int qpow(int x, int y = mod - 2) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = (LL)ret * x % mod;
        x = (LL)x * x % mod, y >>= 1;
    }
    return ret;
}
int n, m, a[MAXN], cnt[MAXN], fac[MAXN], dp[MAXN][MAXN], binom[MAXN][MAXN];
string s;
inline void init() {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = (LL)fac[i - 1] * i % mod;
    for (int i = 0; i <= n; ++i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++j) binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % mod;
    }
}
namespace BF {
    int f[N + 1][1 << N];
    inline void solve() {
        f[0][0] = 1;
        for (int S = 0; S < (1 << n); ++S) {
            int i = __builtin_popcount(S);
            for (int j = 0; j <= i; ++j) if (f[j][S]) {
                for (int k = 0; k < n; ++k) if (!((S >> k) & 1)) inc(f[j + (a[k + 1] <= j || s[i] == '0')][S ^ (1 << k)], f[j][S]);
            }
        }
        int ans = 0;
        for (int i = 0; i <= n - m; ++i) inc(ans, f[i][(1 << n) - 1]);
        cout << ans << '\n';
    }
}; //namespace BF
int main() {
    IOS;
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    init();
    for (int i = 1; i <= n; ++i) cin >> a[i], ++cnt[a[i]];
    for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
    if (m == n) {
        if (count(s.begin(), s.end(), '1') != n || cnt[0]) cout << "0\n";
        else cout << fac[n] << '\n';
        return 0;
    }
    if (m == 1) {
        int ans = 1, c = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') ans = (LL)ans * max(0, cnt[i] - c) % mod;
            c += (s[i] == '1');
        }
        ans = (LL)ans * fac[n - c] % mod;
        cout << (fac[n] + mod - ans) % mod << '\n';
        return 0;
    }
    if (n <= 18) {
        BF::solve();
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            inc(dp[i][j], dp[i - 1][j]);
            if (j && cnt[j - 1] >= j) inc(dp[i][j], (LL)dp[i - 1][j - 1] * (cnt[j - 1] - j + 1) % mod);
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        int cur = (LL)dp[n][i] * fac[n - i] % mod;
        // cerr << i << ' ' << cur << '\n';
        for (int j = i; j <= n; ++j) {
            if (i & 1) dec(ans, cur);
            else inc(ans, cur);
        }
    }
    cout << ans << '\n';
    return 0;
}
/*
3 2
111
1 1 1

3 2
111
0 1 1
*/