#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 998244353;
int C[510][510], A[510][510];
void init() {
    for (int i = 0; i <= 500; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
        A[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            A[i][j] = 1ll * A[i][j - 1] * (i - j + 1) % mod;
        }
    }
}
int n, m, s[510], c[510];
int ss[510], sc[510];
int f[2][510][510];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    init();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%1d", &s[i]);
        ss[i] = ss[i - 1] + s[i];
    }
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        c[x]++;
    }
    sc[0] = c[0];
    for (int i = 1; i <= n; i++) {
        sc[i] = sc[i - 1] + c[i];
    }
    f[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                f[(i & 1) ^ 1][j][k] = 0;
            }
        }
        for (int j = 0; j <= i; j++) {
            for (int k = max(ss[i] - sc[j], 0); k <= ss[i]; k++) {
                if (f[i & 1][j][k]) {
                    // printf("%d %d %d : %d\n", i, j, k, f[(i & 1)][j][k]);
                    if (s[i + 1] == 0) {
                        for (int l = 0; l <= k && l <= c[j + 1]; l++) {
                            f[(i & 1) ^ 1][j + 1][k - l] = (f[(i & 1) ^ 1][j + 1][k - l] + 1ll * f[(i & 1)][j][k] * C[c[j + 1]][l]) % mod;
                        }
                    } else {
                        for (int l = 0; l <= k && l <= c[j + 1]; l++) {
                            f[(i & 1) ^ 1][j + 1][k - l] = (f[(i & 1) ^ 1][j + 1][k - l] + 1ll * f[(i & 1)][j][k] * C[c[j + 1]][l] % mod * (sc[j] - ss[i] + k)) % mod;
                        }
                        f[(i & 1) ^ 1][j][k + 1] = (f[(i & 1) ^ 1][j][k + 1] + 1ll * f[(i & 1)][j][k] * (k + 1)) % mod;
                    }
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= ss[n]; j++) {
            res = (res + 1ll * f[n & 1][i][j] * C[n - sc[i]][j] % mod * A[n - ss[n]][n - ss[n]]) % mod;
        }
    }
    printf("%d\n", res);
    return 0;
}
