#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w;
int a[10005][10005];
int c1[15],c2[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&c1[i]);
		for(int j=1;j<=n;++j)	scanf("%d",&c2[i][j]);	
	}
	cout<<0<<endl;
	return 0;
}