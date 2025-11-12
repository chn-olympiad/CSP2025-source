#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,dp[500005],ans=0,qz=0;
map<ll,ll>mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        ll sr,pos;
        cin>>sr;
        qz=(qz^sr);
        mp[qz]=i;
        if(mp[(k^qz)]!=0||(k^qz)==0)
            pos=mp[(k^qz)]+1,dp[i]=max(dp[i-1],dp[pos-1]+1),ans=max(ans,dp[i]);
        else
            dp[i]=dp[i-1];
    }
    cout<<ans<<"\n";
    return 0;
}
