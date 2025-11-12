#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL n,k,t,a[N],sxor[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sxor[i]=sxor[i-1]^a[i];
    }
    for(LL l=1;l<=n;l++){
        for(LL r=1;r<=n;r++){
            LL x=(sxor[r]^sxor[l-1]);
            if(x==k) t++;
        }
    }
    cout<<t;
    return 0;
}
