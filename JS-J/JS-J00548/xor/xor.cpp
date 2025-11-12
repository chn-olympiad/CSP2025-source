#include<bits/stdc++.h>
using namespace std;
long long n,k,tmp=1;
long long a[500005];
long long sum[500005];
long long ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sum[0]=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]^a[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=tmp;i<=j;i++){
            if((sum[j]^sum[i-1])==k){
                ans++;
                tmp=j+1;
                break;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
