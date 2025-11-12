#include <bits/stdc++.h>

using namespace std;
long long n;
const long long N = 100005;
const long long Mod = 998244353;
long long a[N], f[3][N], sum[N];
long long ans = 0;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%lld", &n);
    for(long long i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    long long maxn = 3 * a[n], op = 1;
    for(long long i = 0; i < a[n]; i++)
        f[0][i] = 1;
    for(long long i = 1; i <= n; i++) {
        for(long long j = 0; j <= maxn; j++) 
            f[op][j] = f[op ^ 1][max(j - a[i], 0ll)] % Mod;
        ans = (ans + f[op][2 * a[i] + a[n]]) % Mod;
        // printf("ans : %lld\n", ans);
        // for(long long j = 0; j <= maxn; j++)
        //     printf("%lld ", f[op][j]);
        // printf("\n");
        for(long long j = 0; j <= maxn; j++)
            f[op][j] = (f[op][j] + f[op ^ 1][j]) % Mod;
        op ^= 1;
    }
    printf("%lld\n", ans);
}