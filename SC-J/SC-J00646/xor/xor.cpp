#include <bits/stdc++.h>

using namespace std;
long long n, k;
const long long N = 5e5 + 10;
long long maxn[N];
long long a[N], f[N], sum[N];
map<long long, long long> pl;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    for(long long i = 1; i <= n; i++)
        scanf("%lld", &a[i]), sum[i] = (sum[i - 1] ^ a[i]);
    for(long long i = 1; i <= n; i++) {
        long long las = pl[(sum[i] ^ k)];
        pl[sum[i]] = i;
        // prlong longf("%lld %lld %lld\n", las, i, sum[i] ^ k);
        if((sum[i] ^ k) == 0 && las == 0) f[i] = 1;
        else if(las != 0) f[i] = maxn[las] + 1;
        maxn[i] = max(maxn[i - 1], f[i]);
    }
    // for(long long i = 1; i <= n; i++)
    //     prlong longf("%lld ", f[i]);
    // prlong longf("\n");
    long long maxx = 0;
    for(long long i = 1; i <= n; i++)
        maxx = max(maxx, f[i]);
    printf("%lld\n", maxx);
}