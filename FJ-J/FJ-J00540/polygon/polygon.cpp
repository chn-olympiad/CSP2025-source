#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],ans,f[2010][30][110],mod=998244353;
void dfs(int s,int p,int x)
{
	if(s>x*2)
	{
		ans=(ans+1)%mod;
	}
	for(int i=p+1;i<=n;i++)
	{
		dfs(s+a[i],i,max(x,a[i]));
	}
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
