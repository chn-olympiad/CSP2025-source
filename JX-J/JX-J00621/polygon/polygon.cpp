#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll a[5005],s[5005],dp[5005][5005],m[5005];
ll jc(ll x){
    ll a=1;
    for(ll i=1;i<=x;++i)a=((a%MOD)*(i%MOD))%MOD;
    return a%MOD;
}
ll c(ll n,ll m){
    return jc(n)/(jc(m)*jc(n-m));
}
ll sumc(ll x){
    ll ans=0;
    for(int i=1;i<=x;++i)ans=(ans%MOD+c(x,i)%MOD)%MOD;
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;++i){
        m[i]=sumc(i);
    }
    for(int i=1;i<=n;++i){
        dp[i][i]=0;
        dp[i][i+1]=0;
    }
    for(int len=3;len<=n;++len){
        for(int i=1;i<=n-len+1;++i){
            int j=i+len-1;
            if(s[j]-s[i-1]>a[i]*2&&len==3){
                dp[i][j]=((dp[i][j]%MOD)+1)%MOD;
            }
            for(int k=i;k<=j-1;++k){
                dp[i][j]=((dp[i][j]%MOD)+(((dp[i][k]%MOD)+(dp[k+1][j]%MOD))%MOD))%MOD;
                if(dp[k+1][j]!=0){
                    dp[i][j]=((dp[i][j]%MOD)+(m[k-i]%MOD))%MOD;
                }
            }
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
        }
    }
    cout<<dp[1][n]-1;
    return 0;
}
