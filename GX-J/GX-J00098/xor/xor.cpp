#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[200005],dp[200005],ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]^=a[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            ll m=a[i]^a[j];
            if(m==k){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    printf("%lld",dp[n]);
    return 0;
}
