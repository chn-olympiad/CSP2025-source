#include<bits/stdc++.h>
using namespace std;
struct qwq{ int u,to,w; }f[1000010];
int n,m,k,a,b,c,tot,ans,cost[1010],hed[1000010],g[1010][1010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
	}
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&cost[i]);
		for(int j=1;j<=n;++j) scanf("%d",&g[i][j]);
	}
	cout<<ans;
	return 0;
}
