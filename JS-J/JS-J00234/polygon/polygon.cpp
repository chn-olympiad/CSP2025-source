#include<bits/stdc++.h>
using namespace std;

const long long P=998244353;
int n,a[5010],more[5010];
long long dp[5010];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    dp[0]=1;
    int t=min(sum,5000);
    for(int i=1;i<=n;i++){
        for(int j=t;j>=a[i];j--){
            dp[j]=(dp[j]+dp[j-a[i]])%P;
        }
    }
    for(int i=1;i<=n;i++){
        dp[a[i]]=(dp[a[i]]+P-1)%P;
    }
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            more[i]+=(a[j]>=i);
        }
    };
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*2%P;
    }
    ans=(ans+P-1-n-n*(n-1)/2)%P;
    for(int i=1;i<=t;i++){
        long long x=more[i]*dp[i]%P;
        ans=(ans+P-x)%P;
    }
    printf("%lld\n",ans);
    return 0;
}
