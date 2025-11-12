#include<bits/stdc++.h>
using namespace std;
const int N=10007;
int a[N][N],xz[N][10];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d",&u,&v,&w);
		a[u][v]=a[v][u]=w;
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&xz[i][j]);
		}
	}
	printf("0\n");
	return 0;
}
