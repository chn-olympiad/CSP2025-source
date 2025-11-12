#include <bits/stdc++.h>
using namespace std;

const int N=5e3+10,mod=998244353;

int n,a[N],b[N],ans=0;

void dfs(int idx,int maxx,int sum,int t)
{
	if(idx==n+1)
	{
		if(t>=3 && sum>2*maxx)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	dfs(idx+1,maxx,sum,t);
	dfs(idx+1,max(maxx,a[idx]),sum+a[idx],t+1);
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans%mod;
	return 0;
}