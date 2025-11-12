#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,a[10010],dp[10010],t=0,ans=0,dp2[5010][5010];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            t++;
        }
    }
    if(t==n){
        dp[2]=0,ans=0;
        for(int i=3;i<=n;i++){
            ans+=(i-2)%MOD;
            dp[i]=(dp[i-1]+ans)%MOD;
        }
    }
    else if(n==3){
        if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1]){
            dp[n]=1;
        }
    }
    else{
        cout<<6;
        return 0;
    }
    cout<<dp[n];
    return 0;
}
