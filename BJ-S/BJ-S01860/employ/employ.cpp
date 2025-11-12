

#include <cstdio>
#include <algorithm>

using namespace std;

const int P = 998244353;
int N, M;
char S[509];
int cnt[509];
int sc[509];
int C[509][509], A[509][509];
int fac[509];
int f[109][109][109], g[109][109];
int res;

int main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &N, &M);
    for (int i = 0; i <= N; i++) {
        C[i][0] = 1, A[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P, A[i][j] = (1ll * A[i][j - 1] * (i - j + 1)) % P;
    }
    scanf("%s", S + 1);
    if (N <= 100) {
        int c;
        fac[0] = 1;
        for (int i = 1; i <= N; i++) scanf("%d", &c), cnt[c]++, fac[i] = (1ll * fac[i - 1] * i) % P;
        sc[0] = cnt[0];
        for (int i = 1; i <= N; i++) sc[i] = sc[i - 1] + cnt[i];
        f[0][0][0] = 1;
        for (int i = 1; i <= N; i++) {
            if (S[i] == '0') {
                for (int j = 0; j < i; j++) {
                    for (int k = 0; k < i; k++) g[j][k] = f[i - 1][j][k];
                    for (int k = 1; k <= i; k++) g[j][k] = (g[j][k] + 1ll * f[i - 1][j][k - 1] * max(sc[j] - k + 1, 0)) % P;
                }
                for (int j = 0; j < i; j++)
                    for (int k = 0; k <= i; k++)
                        if (g[j][k]) {
                            for (int t = 0; t + k <= i; t++) {
                                f[i][j + 1][t + k] = (f[i][j + 1][t + k] + 1ll * g[j][k] * ((1ll * C[i - k][t] * A[cnt[j + 1]][t]) % P)) % P;
                            }
                            g[j][k] = 0;
                        }
            }
            else {
                for (int j = 0; j < i; j++) {
                    for (int k = 0; k < i; k++) f[i][j][k] = f[i - 1][j][k];
                    for (int k = 1; k <= i; k++) g[j][k] = (g[j][k] + 1ll * f[i - 1][j][k - 1] * max(sc[j] - k + 1, 0)) % P;
                }
                for (int j = 0; j < i; j++)
                    for (int k = 0; k <= i; k++)
                        if (g[j][k]) {
                            for (int t = 0; t + k <= i; t++) {
                                f[i][j + 1][t + k] = (f[i][j + 1][t + k] + 1ll * g[j][k] * ((1ll * C[i - k][t] * A[cnt[j + 1]][t]) % P)) % P;
                            }
                            g[j][k] = 0;
                        }
            }
        }
        for (int j = 0; j <= N - M; j++) {
            int k = sc[j];
            res = (res + 1ll * f[N][j][k] * fac[N - k]) % P;
        }
    }
    else puts("0");
    printf("%d\n", res);
    return 0;
}