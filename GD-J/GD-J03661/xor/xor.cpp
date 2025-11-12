#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,ans;
ll a[500010],dp[500010],sum[500010],mp[2000010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=0;i<2000003;i++)mp[i]=-1;
	mp[0]=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=max(dp[i],dp[i-1]);
		sum[i]=sum[i-1]^a[i];
		if(mp[sum[i]^k]!=-1)dp[i]=max(dp[i],dp[mp[sum[i]^k]]+1);
		mp[sum[i]]=i;
		ans=max(ans,dp[i]);
	}
	cout<<ans<<"\n";
	return 0;
} 
