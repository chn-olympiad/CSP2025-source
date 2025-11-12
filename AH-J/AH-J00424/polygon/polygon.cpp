#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e3+10;
LL n,a[N],dp[N][N],mx[N];//dp(i,j) 在i~j个木棍中选择一些拼凑成多边形的方案数
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    if(n<=3) cout<<0;
    else{
        for(LL i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        sort(a+1,a+n+1);
        for(LL i=1;i<=n;i++) mx[i]=mx[i-1]+a[i];

        for(LL i=1;i<=n;i++){//起点
            for(LL j=2;j<=n-i;j++){//划分长度
                LL maxn=-1;
                for(LL s=i;s<=i+j;s++) maxn=max(maxn,a[i]);
                if(mx[i+j]-mx[i-1]>2*maxn){//可以拼凑
                    dp[i][j]=max(dp[i-1][j],dp[i][j]+1);
                }
                else dp[i][j]=dp[i-1][j];//不可以拼凑
            }
        }
        LL sum=0;
        for(LL i=1;i<=n;i++){
            for(LL j=2;j<=n-i;j++){
                cout<<dp[i][j]<<" ";
                sum+=dp[i][j]%998244353;
            }
        }
        cout<<sum%998244353;
    }
    return 0;
}
