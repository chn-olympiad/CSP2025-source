#include <bits/stdc++.h>

using namespace std;
struct r{
	int s;
	int go;
	int v;
}road[1000005];
int s_val[15];
int val[15][1000005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,mon;
		cin>>u>>v>>mon;
		road[i].v=mon;
		road[i].s=u;
		road[i].go=v;
	}
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		cin>>s_val[i];
		for(int j=1;j<=n;j++)
		{
			cin>>val[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		ans=ans+road[i].v;
	}
	cout<<ans;
	return 0;
}

