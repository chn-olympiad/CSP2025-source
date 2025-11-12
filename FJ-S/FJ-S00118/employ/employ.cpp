#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
const int mod = 998244353;
char s[N];
int n, m, ans;
int c[N];
bool used[N];
int p[N], fac[N], inv[N];
// ==========================
void chk() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (cnt >= c[p[i]] || s[i] == '0') cnt++;
    cnt = n - cnt;
    if (cnt >= m) ans++;
}
void dfs(int now) {
    if (now == n + 1) return chk();
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            p[now] = i, used[i] = true;
            dfs(now + 1);
            used[i] = false;
        }
    }
}
void solve_n10() { dfs(1); }
// ==========================
void solve_mn() {
    for (int i = 1; i <= n; i++)
        if (c[i] == 0) return;
    ans = 1;
    for (int i = 1; i <= n; i++) ans = ans * i % mod;
}
// ==========================
inline int qpow(int x, int y = mod - 2) {
    int res = 1;
    for (; y; y >>= 1, x = x * x % mod)
        if (y & 1) res = res * x % mod;
    return res;
}
inline void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = qpow(fac[N - 1]);
    for (int i = N - 1; i; i--) inv[i - 1] = inv[i] * i % mod;
}
// ==========================
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> (s + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    bool flag_s1 = true;
    for (int i = 1; i <= n; i++) if (s[i] == '0') { flag_s1 = false; break; }
    ans = 0;
    if (n <= 10) solve_n10();
    else solve_mn();
    cout << ans;
}