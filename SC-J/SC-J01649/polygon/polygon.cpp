#include<cstdio>
#include<algorithm>
#define N 5005
int n,a[N],dp[N],mod=998244353,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dp[0]=1,std::sort(a+1,a+n+1);
    for(int i=1,base2=1;i<=n;i++,base2=(base2<<1)%mod){
        ans=(ans+base2)%mod;
        for(int j=0;j<=a[i];j++)ans=(ans+mod-dp[j])%mod;
        for(int j=5000;j>=a[i];j--)dp[j]=(dp[j]+dp[j-a[i]])%mod;
    }
    printf("%d",ans);
}