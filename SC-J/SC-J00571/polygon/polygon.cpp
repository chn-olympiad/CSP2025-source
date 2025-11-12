#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10005, mod = 998244353;

inline int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

int fac[N], invfac[N];

inline int C(int n, int m) {
    if (n < m) return 0;
    return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

int n, a[N];

int ans;

int f[5][N];

signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = (fac[i - 1] * i) % mod;
    invfac[N - 1] = qpow(fac[N - 1], mod - 2);
    for (int i = N - 1; i >= 1; i--) {
        invfac[i - 1] = (invfac[i] * i) % mod;
    }

    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= i - 1; j++) {
            // printf("%lld %lld %lld\n", i, j, C(i - 1, j));
            ans += C(i - 1, j);
            if (ans >= mod) ans -= mod;
        }
        for (int j = 1; j <= a[i]; j++) {
            ans += mod - f[3][j];
            if (ans >= mod) ans -= mod;
            ans += mod - f[2][j];
            if (ans >= mod) ans -= mod;
        }

        // printf("%lld %lld\n", i, ans);

        f[1][a[i]]++;
        for (int j = N - 1; j > a[i]; j--) {
            if (j - a[i] != a[i]) f[2][j] += f[1][j - a[i]];
            else f[2][j] += f[1][j - a[i]] - 1;
            if (f[2][j] >= mod) f[2][j] -= mod;
            // if (j - a[i] != a[i]) f[3][j] += f[2][j - a[i]];
            f[3][j] += f[2][j - a[i]];
            if (f[3][j] >= mod) f[3][j] -= mod;
            // if (j - a[i] != a[i]) f[3][j] += f[3][j - a[i]];
            f[3][j] += f[3][j - a[i]];
            if (f[3][j] >= mod) f[3][j] -= mod;
        }
    }

    // for (int i = 1; i <= a[n]; i++) {
    //     printf("%lld %lld %lld %lld\n", i, f[1][i], f[2][i], f[3][i]);
    // }

    printf("%lld\n", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}