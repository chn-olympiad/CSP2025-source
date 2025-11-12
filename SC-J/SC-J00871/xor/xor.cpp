#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,k;
ll dp[N],sum[N],a[N],pre[N];
unordered_map<ll,ll>vis;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++)
		sum[i]=sum[i-1]^a[i];
	vis[0]=0;
	for(ll i=1;i<=n;i++)
	{
		if(vis[k^sum[i]]||(k^sum[i])==0)
		{
			pre[i]=vis[k^sum[i]];
			vis[sum[i]]=i;
		}
		else
		{
			pre[i]=-1;
			vis[sum[i]]=i;
		}
	}
//	for(ll i=1;i<=n;i++)
//		cout<<sum[i]<<" ";
//	cout<<'\n';
//	for(ll i=1;i<=n;i++)
//		cout<<pre[i]<<'\n';
	ll ans=0;
	for(ll i=1;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]);
		if(pre[i]!=-1)
			dp[i]=max(dp[i],dp[pre[i]]+1);
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}