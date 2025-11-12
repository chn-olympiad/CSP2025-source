#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
int n,a[5005],sum,maxx,ans,maxxx;
void dfs(int k)
{
	if(k==n+1)
	{
		if(sum>a[maxx]*2) ans=(ans%mod+1)%mod;
		return;
	}
	int org=maxx;
	maxx=k;
	sum+=a[k];
	dfs(k+1);
	maxx=org;
	sum-=a[k];
	dfs(k+1);
	return;
}
int fpow(int base,int c)
{
	int ans=1;
	while(c)
	{
		if(c&1) ans=ans%mod*base%mod;
		base=base%mod*base%mod;
		c>>=1;
	}
	return ans%mod;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[n]>1) dfs(1);
	else
	{
		ans=(fpow(2,n)-1-n-n*(n-1)/2%mod+mod)%mod;
	}
	cout<<ans%mod;
	return 0;
}
