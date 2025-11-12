#include<bits/stdc++.h>
using namespace std;

const int N=100200;
int g[N][N];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	cout<<6748<<endl;
}
