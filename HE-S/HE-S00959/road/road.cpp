#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	int a[m+1];
	int e[m+1][m+1];
	memset(a,0,sizeof(a));
	int c;
	int d[m+1];
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		a[u]++;
		e[v][2]=u;
	}
	for(int i=0;i<k;i++)
	{
		cin>>c;
		for(int j=1;j<=m;j++)
		{
			cin>>d[j];
		}
	}
	int b;
	int maxx;
	for(int i=1;i<=m;i++)
	{
		maxx=max(a[i],a[i-1]);
	}
	for(int i=0;i<=m;i++)
	{
		if(a[i]==maxx)
		{
			b=i;
		}
	}
	int f[m+1];
	for(int i=1;i<=m;i++)
	{
		if(e[i][1]==u)
		{
			f[i]=i;
		}
	}
	return 0;
}
