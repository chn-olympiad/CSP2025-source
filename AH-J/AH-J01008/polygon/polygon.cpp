#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL a[5010];
LL dp[20010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    LL ans=0;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=20001;j>=a[i];j--){
            if(j>a[i]*2){
                ans+=dp[j-a[i]];
            }
            dp[j]+=dp[j-a[i]];
            dp[j]%=998244353;
        }
        for(int j=15001;j<=20001;j++){
            dp[j-5000]+=dp[j];
            dp[j]=0;
        }
    }
    ans%=998244353;
    printf("%lld",ans);
    return 0;
}
