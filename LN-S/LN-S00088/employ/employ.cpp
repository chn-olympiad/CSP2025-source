#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, s[505], c[505], cnt;
long long jc[505];
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    jc[0] = 1;
    for(int i = 1; i <= n; i++) jc[i] = jc[i-1] * i % mod;
    for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
    for(int i = 1; i <= n; i++){
        scanf("%d", &c[i]);
        if(c[i] == 0) ++cnt;
    }
    if(n-cnt < m) printf("0");
    else printf("%lld", (jc[n] + 1ll*(n-1)*jc[n-cnt]%mod) % mod);
return 0;
}
