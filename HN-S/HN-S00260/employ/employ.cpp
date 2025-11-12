#include <cstdio>

constexpr int MAX_N = 500 + 2;
constexpr int P = 998244353;

int n, m;
int cnt[MAX_N], pre[MAX_N], fac[MAX_N], iFac[MAX_N];
int f[MAX_N][MAX_N], g[MAX_N][MAX_N], h[MAX_N][MAX_N];

char s[MAX_N];

int quickPower(int x, int k) {
    int ret = 1;

    for (; k; k >>= 1, x = 1ll * x * x % P) {
        if (k & 1) {
            ret = 1ll * ret * x % P;
        }
    }

    return ret;
}

int inverse(int x) {
    return quickPower(x, P - 2);
}

int A(int x, int y) {
    return 1ll * fac[x] * iFac[x - y] % P;
}

int C(int x, int y) {
    return 1ll * A(x, y) * iFac[y] % P;
}

void add(int &x, int y) {
    (x += y) >= P && (x -= P);
}

void add(int &x, int y, int z) {
    x = (x + 1ll * y * z) % P;
}

void init() {
    pre[0] = cnt[0];

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + cnt[i];
    }

    fac[0] = 1;

    for (int i = 1; i <= n; i++) {
        fac[i] = 1ll * fac[i - 1] * i % P;
    }

    iFac[n] = inverse(fac[n]);

    for (int i = n; i; i--) {
        iFac[i - 1] = 1ll * iFac[i] * i % P;
    }
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    scanf("%d%d%s", &n, &m, s + 1);

    for (int i = 1, c; i <= n; i++) {
        scanf("%d", &c);

        cnt[c]++;
    }

    init();

    f[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i && k <= pre[j]; k++) {
                if (!f[j][k]) {
                    continue;
                }

                if (s[i] == '0') {
                    add(g[j + 1][k], f[j][k]);
                } else {
                    add(h[j][k], f[j][k]);
                }

                add(g[j + 1][k + 1], f[j][k], pre[j] - k);
            }
        }

        for (int j = 1; j <= i; j++) {
            for (int k = 0; k <= i && k <= pre[j - 1]; k++) {
                if (!g[j][k]) {
                    continue;
                }

                for (int c = 0; c <= cnt[j] && k + c <= i; c++) {
                    add(h[j][k + c], g[j][k],
                      1ll * A(cnt[j], c) * C(i - k, c) % P);
                }

                g[j][k] = 0;
            }
        }

        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i && k <= pre[j]; k++) {
                f[j][k] = h[j][k];
                h[j][k] = 0;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= n - m; i++) {
        add(ans, f[i][pre[i]], fac[n - pre[i]]);
    }

    printf("%d\n", ans);

    return 0;
}
