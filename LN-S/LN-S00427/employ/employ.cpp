#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;

#define vi vector<int>
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define bit(k) (1 << (k))
#define bin(s, k) (((s) >> (k)) & 1)
#define mem(a, x) memset(a, x, sizeof(a))
#define req(i, l, r) for (int i = l, i##End = r; i < i##End; i = -~i)
#define rep(i, l, r) for (int i = l, i##End = r; i <= i##End; i = -~i)
#define per(i, r, l) for (int i = r, i##End = l; i >= i##End; i = ~-i)

bool Mbe;

template<typename T, typename U> void chkmx(T &a, U b) { if (a < b) a = b; }
template<typename T, typename U> void chkmn(T &a, U b) { if (a > b) a = b; }

#define N 505
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

void add(int &a, int b) { a += b; if (a >= mod) a -= mod; }
void add(i64 &a, i64 b) { a += b; if (a >= mod) a -= mod; }

i64 qpow(i64 a, i64 b = mod - 2) {
    i64 ml = 1, bs = a % mod;
    while (b) {
        if (b & 1) ml = ml * bs % mod;
        bs = bs * bs % mod, b >>= 1;
    } return ml;
}

i64 fac[N], inv[N];

i64 C(int n, int m) {
    if (n < m || m < 0) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int n, m;
char S[N];
int a[N];
int b[N];

namespace T1 {
    constexpr int M = 262155;
    int f[M][19];

    void mslv() {
        f[0][0] = 1;
        req(s, 0, bit(n)) {
            int c = __builtin_popcount(s) + 1;
            rep(x, 0, c) {
                rep(i, 1, n) if (!bin(s, i - 1)) {
                    add(f[s | bit(i - 1)][x + (S[c] == '0' || x >= b[i])], f[s][x]);
                }
                // fprintf(stderr, "f[%d][%d] = %d\n", s, x, f[s][x]);
            }
        } int ans = 0;
        rep(x, m, n) add(ans, f[bit(n) - 1][n - x]);
        printf("%d\n", ans);
    }
} // T1 : n <= 18

namespace T2 {
    void mslv() {
        if (a[n] || !b[1]) { puts("0"); return; }
        i64 ans = 1;
        rep(i, 1, n) ans = ans * i % mod;
        printf("%lld\n", ans);
    }
} // T2 : m = n

namespace T3 {
    int k;
    i64 f[N][N];
    i64 g[N], h[N];

    void mslv() {
        k = 1; while (k <= n && !b[k]) k++; k--;
        if (n - m + 1 - k < 0) { puts("0"); return; }
        // fprintf(stderr, "k = %d\n", k);
        // rep(i, 0, n) fprintf(stderr, "fac[%d] = %lld\n", i, fac[i]);
        rep(t, 0, n - k) {
            f[n + 1][0] = 1;
            per(i, n, k + 1) rep(j, 0, min(t, n - i + 1)) {
                f[i][j] = f[i + 1][j];
                if (!j) continue;
                i64 x = k + t - b[i] - j + 1;
                if (x > 0) add(f[i][j], f[i + 1][j - 1] * x % mod);
            } g[t] = f[k + 1][t] * C(n, k + t) % mod * (fac[k] * fac[n - (k + t)] % mod) % mod;
            // per(i, n, k + 1) rep(j, 0, min(t, n - i + 1))
            //     fprintf(stderr, "f[%d][%d] = %lld\n", i, j, f[i][j]);
            // fprintf(stderr, "g[%d] = %lld\n", t, g[t]);
            // fprintf(stderr, "%lld | %lld | %lld | %lld\n", f[k + 1][t], C(n, k + t), fac[k], fac[n - (k + 1)]);
        }
        // i64 ans = 0;
        rep(t, 0, n - m) {
            i64 res = 0;
            rep(i, 0, n - k - t) {
                if (i & 1) res -= g[i + t];
                else res += g[i + t];
            // } ans += res;
            } h[t] = res;
            // fprintf(stderr, "t = %d | res = %lld\n", t, res);
        }
        per(t, n - m, 0) h[t] += h[t + 1];
        // fprintf(stderr, "ans = %lld\n", ans);
        // fprintf(stderr, "n - m + 1 - k = %d\n", n - m + 1 - k);
        printf("%lld\n", ((fac[n] - h[n - m + 1 - k]) % mod + mod) % mod);
        // printf("%lld\n", (ans * fac[k] % mod + mod) % mod);
    }
} // T3 : s[i] = 1

void mslv() {
    scanf("%d%d", &n, &m), scanf("%s", S + 1);
    rep(i, 1, n) scanf("%d", b + i), a[i] = a[i - 1] + (S[i] == '0');
    sort(b + 1, b + n + 1);
    if (n <= 18) return T1::mslv();
    if (m == n) return T2::mslv();
    if (!a[n]) return T3::mslv();
    puts("0");
}

void mprw() {
    n = N - 1, fac[0] = 1; rep(i, 1, n) fac[i] = fac[i - 1] * i % mod;
    inv[n] = qpow(fac[n]); per(i, n, 1) inv[i - 1] = inv[i] * i % mod;
}

bool Med;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    mprw(), mslv();
    #ifdef JYR
    fprintf(stderr, "%.2lfMB ", abs(&Mbe - &Med) / 1048576.);
    fprintf(stderr, "%.0lfms\n", clock() * 1000. / CLOCKS_PER_SEC);
    #endif
    return 0;
}