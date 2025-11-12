#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL a[N],xor_a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    LL n,k,ans=0;
    scanf("%lld%lld",&n,&k);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        xor_a[i]=xor_a[i-1]^a[i];
    }
    LL l=1;
    for(LL r=1;r<=n;r++){
        if(l<=r){
            LL sum=xor_a[r]^xor_a[l-1];
            if(sum==k){
                ans++;
                l=r-1;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
