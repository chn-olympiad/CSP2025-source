#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int n;
int a[5010];
int ans;
long long fac[5010], ifac[5010];
int dp[110][50010];
int ndp[110][50010];
int c[50010], d[50010];

int read (){
    char ch = getchar();
    int ans = 0;
    while(ch < '0' && ch > '9')
        ch = getchar();
    while(ch >= '0' && ch <= '9') {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}

long long ksm (long long a, long long b) {
    long long res = 1;
    while(b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long comb (long long a, long long b) {
    return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

int main (){
    //printf("use : %.10f\n", (sizeof(n) + sizeof(a) + sizeof(ans) + sizeof(fac) + sizeof(ifac) + sizeof(dp) + sizeof(ndp) + sizeof(c) + sizeof(d)) / 1024. / 1024.);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    n = read();
    int cc = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (a[i] != 1) cc = 1;
    }
    for (int i = 1; i <= n + 1; i++) {
        c[i] = c[i - 1] + a[i];
        d[i] = max(d[i - 1], a[i]);
    }
    if ((cc == 1 && n <= 500)) {
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= d[i + 1]; j++) {
                for (int k = 0; k <= c[i + 1]; k++) {
                    ndp[j][k] = 0;
                }
            }
            for (int j = 0; j <= d[i]; j++) {
                for (int k = 0; k <= c[i]; k++) {
                    ndp[j][k] += dp[j][k];
                    ndp[j][k] %= mod;
                    if (k + a[i + 1] <= c[i + 1]) {
                        ndp[max(j, a[i + 1])][k + a[i + 1]] += dp[j][k];
                        ndp[max(j, a[i + 1])][k + a[i + 1]] %= mod;
                    }
                }
            }
            for (int j = 0; j <= d[i + 1]; j++) {
                for (int k = 0; k <= c[i + 1]; k++) {
                    dp[j][k] = ndp[j][k];
                }
            }
           // if (i % 100 == 0)
           //     printf("%d\n", i);
        }
        long long ans = 0;
        for (int j = 0; j <= d[n + 1]; j++) {
            for (int k = 2 * j + 1; k <= c[n + 1]; k++) {
                if (k > 2 * j) {
                    ans += dp[j][k];
                    ans %= mod;
                }
            }
        }
        printf("%lld\n", ans);
    } else {
        fac[0] = 1;
        for (int i = 1; i <= 5000; i++)
            fac[i] = fac[i - 1] * i % mod;
        ifac[5000] = ksm(fac[5000], mod - 2);
        for (int i = 5000; i >= 1; i--)
            ifac[i - 1] = ifac[i] * i % mod;
        long long ans = 0;
        for (int i = 3; i <= n; i++) {
            ans += comb(n, i);
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
