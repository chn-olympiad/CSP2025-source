#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll Read() {
    int sig = 1; ll x = 0; char c = getchar();
    while(!isdigit(c)) { if(c == '-') sig = -1; c = getchar(); }
    while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    return x * sig;
}
void Write(ll x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) Write(x / 10);
    putchar((x % 10) ^ 48);
}
const int N = 505;
const ll Mod = 998244353;
int n, m, cnt[N], sum[N], s[N];
ll f[2][N][N], fact[N], ifact[N], ans;
ll QuickPow(ll x, ll y, ll Mod) {
    ll res = 1ll;
    while(y) {
        if(y & 1) res = res * x % Mod;
        x = x * x % Mod, y >>= 1;
    }
    return res;
}
void Init_fact(int n) {
    int i; fact[0] = ifact[0] = 1ll;
    for(i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % Mod;
    ifact[n] = QuickPow(fact[n], Mod - 2, Mod);
    for(i = n - 1; i; i--) ifact[i] = ifact[i + 1] * (i + 1) % Mod;
}
void Add(ll &x, ll y) { x += y; if(x >= Mod) x -= Mod; }
ll C(int n, int m) { return fact[n] * ifact[n - m] % Mod * ifact[m] % Mod; }
int main() {
    freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
    int i, j, k, l; bool o = false; char c;
    n = Read(), m = Read(), c = getchar(), Init_fact(n);
    while(!isdigit(c)) c = getchar();
    for(i = 1; i <= n; i++) s[i] = c ^ '0', c = getchar();
    for(i = 1; i <= n; i++) cnt[Read()]++;
    sum[0] = cnt[0];
    for(i = 1; i <= n; i++) sum[i] = sum[i - 1] + cnt[i];
    f[o][0][0] = 1;
    for(i = 1; i <= n; i++, o ^= 1) for(j = 0; j < i; j++) for(k = 0; k < i; k++) if(f[o][j][k]) {
        if(s[i]) {
            Add(f[o ^ 1][j][k + 1], f[o][j][k] * (k + 1) % Mod);
            int r = sum[j] - (i - 1 - k); ll t = f[o][j][k] * r % Mod;
            if(t) for(l = min(cnt[j + 1], k); l >= 0; l--) Add(f[o ^ 1][j + 1][k - l], t * C(cnt[j + 1], l) % Mod);
        }
        else {
            int r = sum[j] - (i - 1 - k);
            ll t = f[o][j][k] * r % Mod, t_ = f[o][j][k] * (k + 1) % Mod;
            for(l = min(cnt[j + 1], k + 1); l >= 0; l--) {
                if(t && l <= k) Add(f[o ^ 1][j + 1][k - l], t * C(cnt[j + 1], l) % Mod);
                Add(f[o ^ 1][j + 1][k - l + 1], t_ * C(cnt[j + 1], l) % Mod);
            }
        }
        f[o][j][k] = 0ll;
    }
    for(i = 0; i <= n - m; i++) Add(ans, f[o][i][n - sum[i]]);
    Write(ans);
}
