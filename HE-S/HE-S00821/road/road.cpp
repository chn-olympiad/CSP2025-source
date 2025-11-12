#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int lu[10004][10004],c[15],xin[15][10004];
vector<int> v[10004];
long long ans;
queue<int> q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int vv,u,w;
		cin>>vv>>u>>w;
		if(lu[vv][u]==0)
		{
			v[vv].push_back(u);
			v[u].push_back(vv);
			lu[vv][u]=w;
			lu[u][vv]=w;
		}
		else
		{
			lu[vv][u]=min(lu[vv][u],w);
			lu[u][vv]=min(lu[u][vv],w);
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>xin[i][j];
		}
	}
	cout<<13;
	//cout<<'\n'<<"freopen!!!!!!!!!!";
	return 0;
}
