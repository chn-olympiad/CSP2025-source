#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
bool f[N];
LL n,k,cnt,a[N],sum[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(LL i=1;i<=n;i++){
        scanf("%lld",a+i);
        sum[i]=sum[i-1]^a[i];
        if(a[i]==k){
            cnt++;
            f[i]=true;
        }
    }
    for(LL i=1;i<=n;i++)
        for(LL j=i+1;j<=n;j++){
            LL sumk=sum[j]^sum[i-1];
            if(sumk==k){
                bool pos=false;
                for(LL l=i;l<=j;l++) if(f[l]){pos=true;break;}
                if(!pos){
                    for(LL l=i;l<=j;l++) f[l]=true;
                    cnt++;
                }
            }
        }
    printf("%lld",cnt);
    return 0;
}
