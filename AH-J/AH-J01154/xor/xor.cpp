#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL n,k,x,sum=0,pos=0,a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(LL i=1;i<=n;i++){
        x=0;
        for(LL j=i;j<=n;j++){
            x^=a[j];
            if(x==k&&j>pos){
                sum++;
                pos=j;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
