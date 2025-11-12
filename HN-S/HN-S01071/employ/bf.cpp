#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 505, mod = 998244353;
int n, m;
string s;
int a[maxn], sa[maxn];
int dp[maxn][maxn];
int fac[maxn], ifac[maxn];
int b[maxn], c[maxn], sb[maxn], sc[maxn];
int ans;
int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}
void init(int n) {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod, ifac[i] = ifac[i - 1] * power(i, mod - 2) % mod;
}
int A(int n, int m) {
    if (m == 0) return 1;
    if (m < 0 || m > n) return 0;
    return fac[n] * ifac[n - m] % mod;
}
int calc(int x) {
    memset(dp, 0, sizeof(dp));
    dp[n + 1][0] = 1;
    for (int i = n; i >= 0; i--)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= min(j, a[i]); k++) {
                int s = dp[i + 1][j - k];
                s = s * A(x - i - (j - k), k) % mod;
                s = s * A(n - x - sa[i + 1] + (j - k) + min(i - 1, x), a[i] - k) % mod;
                dp[i][j] = (dp[i][j] + s) % mod;
            }
    return dp[0][x];
}
int calc() {
    for (int i = n; i >= 0; i--) sb[i] = sb[i + 1] + b[i];
    sc[0] = c[0];
    for (int i = 1; i <= n; i++) sc[i] = sc[i - 1] + c[i];
    int res = 1, x = sb[0];
    if (x > n - m) return 0;
    for (int i = 0; i <= n; i++) {
        res = res * A(x - i - sb[i + 1], b[i]) % mod;
    }
    // cout << res << endl;
    for (int i = 0; i <= n; i++) {
        res = res * A(sc[i] + min(i - 1, x), c[i]) % mod;
    }
    return res;
}
void dfs(int k) {
    if (k == -1) {ans = (ans + calc()) % mod; return;}
    for (int i = 0; i <= a[k]; i++) {
        b[k] = i, c[k] = a[k] - i;
        dfs(k - 1);
    }
}
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> s; s = " " + s; init(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    for (int i = n; i >= 0; i--) sa[i] = sa[i + 1] + a[i];
    // for (int i = 0; i <= n - m; i++) ans = (ans + calc(i)) % mod;
    dfs(n);
    cout << ans << endl;
    return 0;
}