#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005],dp[5005],mod=998244353,ans;
ll add(ll a,ll b){
    return (a+b)%mod;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    dp[0]++;
    dp[a[1]]++;
    dp[a[2]]++;
    dp[a[1]+a[2]]++;
    for(ll i=3;i<=n;i++){
        for(ll j=a[i]+1;j<=5001;j++)
            ans=add(ans,dp[j]);
        for(ll j=5001;j>=0;j--){
            ll pos=min(5001ll,j+a[i]);
            dp[pos]=add(dp[pos],dp[j]);
        }
    }
    cout<<ans;
    return 0;
}
