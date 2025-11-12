#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,u,v,a[1011];
int w,g[1011][1011],c[11],vc[11];
struct road{
	int u,v,w;
}r[1100001];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("raod.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(g,0x3f,sizeof g);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		sum+=w;
		g[u][v]=min(w,g[u][v]);
		r[i]=road{u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",c+i);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&w);
			g[1000+i][j]=w+c[i];
		}
	}
	for(int i=1;i<=k;i++)vc[i]=1;
	printf("%d",sum);
	return 0;
}
