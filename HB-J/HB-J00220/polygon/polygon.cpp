#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5010],b,dp[50010];
inline long long qpow(long long x){
    long long b=mod-2,res=1;
    while(b){
        if(b&1)res=(res*x)%mod;
        x=(x*x)%mod;
        b>>=1;
    }
    return res;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    if(a[n]==1&&n>=3){
        long long nn=1,mm=2,ans=0;
        for(long long i=2;i<=n;i++)nn=(nn*i)%mod;
        for(long long i=3;i<=n;i++){
            mm=(mm*i)%mod;
            long long k=n-i;
            long long mn=1;
            for(long long j=2;j<=k;j++)mn=(mn*j)%mod;
            long long inv=qpow(mn*mm%mod);
            long long cnt=nn*inv%mod;
            ans=(ans+cnt)%mod;
        }
        printf("%lld",ans);
        return 0;
    }
    long long ans=0;
    for(long long i=1;i<=n;i++){
        b+=a[i];
        if(2*a[i]>=b)continue;
        long long mx=0;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        long long m=i-1,x=a[i];
        for(long long p=1;p<=m;p++){
            long long mm=0;
            for(long long j=mx;j>=0;j--){
                if(dp[j]==0)continue;
                dp[j+a[p]]=(dp[j+a[p]]+dp[j])%mod;
                if(j+a[p]>mm)mm=j+a[p];
            }
            if(mm>mx)mx=mm;
        }
        long long res=0;
        for(long long j=x+1;j<=mx;j++){
            res=(res+dp[j])%mod;
            //cout<<j<<" "<<dp[j]<<"-->"<<i<<"\n";
        }
        //cout<<i<<" "<<res<<"\n";
        ans=(ans+res)%mod;
    }
    printf("%lld",ans);
    return 0;
}
