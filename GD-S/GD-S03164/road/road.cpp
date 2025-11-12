#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,f[10002][10002];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		f[u][v]=0;
		f[v][u]=0;
	}
	return 0;
}
