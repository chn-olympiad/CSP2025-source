#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL n,k,a[N],Xor[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(LL i=1; i<=n; i++) scanf("%lld",&a[i]);
    bool f=0;
    for(LL i=1; i<=n; i++) if(a[i]!=1) f=1;
    if(f==0){
        printf("%lld",n/2);
        return 0;
    }
    bool ok=0;
    for(LL i=1; i<=n; i++){
        if(a[i]!=0&&a[i]!=1) ok=1;
    }
    if(ok==0){
        LL cnt0=0,cnt1=0;
        for(LL i=1; i<=n; i++){
            if(a[i]==0) cnt0++;
            if(a[i]==1) cnt1++;
        }
        LL ans=0;
        if(k==0) ans+=cnt0+cnt1/2;
        else ans=cnt1;
        printf("%lld",ans);
        return 0;
    }
    LL cnt=0;
    Xor[1]=a[1];
    for(LL i=2; i<=n; i++) Xor[i]=Xor[i-1]^a[i];
    for(LL l=1; l<=n; l++){
        for(LL r=l; r<=n; r++){
            if((Xor[r]^Xor[l-1])==k){
                l=r;
                cnt++;
                break;
            }
        }
    }
    printf("%lld",cnt);
    return 0;
}
