#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
int a[500005];
int id_fr[500005];
int dp[500005];
int ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=5000;i++)id_fr[i]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(id_fr[a[i]^k]>=0)dp[i]=max(dp[i],dp[id_fr[a[i]^k]]+1);
		id_fr[a[i]]=i;
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
