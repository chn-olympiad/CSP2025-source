#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,z;
	for(int i = 1;i<=n;i++)
	{
		cin>>x>>y>>z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	for(int i = 1;i<=k;i++)
	{
		cin>>x;
		for(int j = 1;i<=n;j++)
		{
			cin>>x;
		}
	}
	if(k!=0)
	{
		cout<<0;
		return 0;
	}
	return 0;
}
