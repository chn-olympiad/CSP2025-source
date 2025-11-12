#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,t,ans,f[50010];
void dfs(int lev,int ma,int sum)
{
	if(lev==n+1)
	{
		if(sum>ma*2) ans++;
		return ;
	}
	dfs(lev+1,ma,sum);
	dfs(lev+1,max(ma,f[lev]),sum+f[lev]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>f[i];
		t=max(t,f[i]);
	}
	if(t==1)
	{
		long long p=(n-2)*(n-1)/2;
		cout<<p%mod;
		return 0;
	}
	if(n<=20)
	{
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	long long e=pow(2,t);
	cout<<e%mod;
	return 0;
}
