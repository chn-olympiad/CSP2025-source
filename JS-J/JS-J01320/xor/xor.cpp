#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,k;
ll a[N],sum[N],dp[N];
unordered_map<ll,ll> mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
    dp[0]=0;
    mp[0]=0;
    for(int i=1;i<=n;i++){
        ll tar=sum[i]^k;
        if(mp.count(tar)) dp[i]=max(dp[mp[tar]]+1,dp[i-1]);
        else dp[i]=dp[i-1];
        mp[sum[i]]=i;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
