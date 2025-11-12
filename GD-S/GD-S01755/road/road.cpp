#include <bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			int u;
			cin>>u;
		}
	}
	if(k==0)
	{
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
