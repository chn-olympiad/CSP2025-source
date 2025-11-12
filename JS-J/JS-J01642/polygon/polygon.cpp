#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,dp[5005][5005];
const long long MOD=998244353;
long long qpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b/=2;
    }
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n;i++) dp[i][0]=qpow(2,i)%MOD;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5002;j++){
            dp[i][j]=dp[i-1][j]%MOD;
            dp[i][j]=(dp[i][j]+dp[i-1][max(0ll,j-a[i])])%MOD;
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++) ans=(ans+dp[i-1][a[i]+1])%MOD;
    cout<<ans<<endl;
    return 0;
}