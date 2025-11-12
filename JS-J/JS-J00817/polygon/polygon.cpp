#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],mod=998244353,dp[5005][5005],sum[5005],ans;
int gn(int x){return min(x,5001ll);}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    dp[0][0]=1;
    sum[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=5001;j>-1;j--){
            dp[i][j]=sum[j];
            (sum[gn(j+a[i])]+=dp[i][j])%=mod;
            if(j>a[i])(ans+=dp[i][j])%=mod;
        }
    }
    printf("%lld",ans);
    return 0;
}
