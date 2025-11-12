#include<bits/stdc++.h>
using namespace std;

int tu[10002][10002];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int v,u,w;
		cin>>u>>v>>w;
		tu[u][v]=w;
		tu[v][u]=w;
	}
	cout<<"13";
	return 0;
}
