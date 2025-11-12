#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll n, a[5010], sum[5010], cnt;
ll d[5010][5010];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%lld", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    for(int i=1; i<=n; i++) d[i][0] = (2 * d[i - 1][0] + 1) % MOD;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=a[n]; j++){
            if(a[i] > j) d[i][j] = (d[i - 1][j] + d[i - 1][0] + 1) % MOD;
            else d[i][j] = (d[i - 1][j] + d[i - 1][j - a[i]]) % MOD;
        }
        if(i >= 3) cnt += (d[i - 1][a[i]]) % MOD;
    }
    printf("%lld", cnt % MOD);
    return 0;
}
