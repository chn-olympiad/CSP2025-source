#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 998244353LL;
ll n, a[5005], dp[5005];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%lld", &n);
    for(ll i = 1;i <= n;i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    dp[1] = 0LL;
    dp[2] = 0LL;
    for(ll i = 3;i <= n;i++){
        ll tmp = 0LL;
        for(ll j = 1;j < i - 1;j++){
            ll b = a[i] - a[j];
            ll pos1 = upper_bound(a + 1, a + i, b) - a;
            ll pos2 = lower_bound(a + 1, a + i, b) - a;
            if(pos2 != i && a[pos2] == b){
                tmp = (tmp + ((((1LL << (i - 3LL)) - 1LL) % MOD)) % MOD) % MOD;
            }
            if(pos1 != i){
                tmp = (tmp + (((1LL << (i - 3LL)) % MOD)) % MOD) % MOD;
            }
        }
        tmp = tmp >> 1LL;
        dp[i] = (dp[i - 1] + tmp) % MOD;
    }
    dp[n] = dp[n] % MOD;
    printf("%lld\n", dp[n]);
    return 0;
}
