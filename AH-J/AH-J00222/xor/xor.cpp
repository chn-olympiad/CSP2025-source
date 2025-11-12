#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long dp[500005];
long long a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    long long maxn=0,pos=0;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long pp=a[1];
    if(pp==k){
        dp[1]=1;
    }
    if(dp[1]>maxn){
        maxn=dp[1];
        pos=1;
    }
    for(long long i=2;i<=n;i++){
        pp^=a[i];
        long long s=pp;
        if(s==k){
            dp[i]=1;
        }
        for(long long j=1;j<i;j++){
            s^=a[j];
            dp[i]=max(dp[i],dp[j]+(s==k));
        }
        if(dp[i]>maxn){
            maxn=dp[i];
            pos=i;
        }
    }
    cout<<dp[n];
    return 0;
}
