#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5010,MOD=998244353;
LL n,a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(LL i=1; i<=n; i++) scanf("%lld",&a[i]);
    if(n<=3){
        cout<<1;
        return 0;
    }
    LL ans=(1+n-2)*(n-2)/2;
    printf("%lld",ans);
    return 0;
}

