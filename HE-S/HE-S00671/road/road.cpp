#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int cnt;
struct Edge{
	int fro;
	int t;
	int w;
}ed[2*M];
int dis[N];
void add(int u,int v,int wh)
{
	ed[++cnt].fro=u;
	ed[cnt].t=v;
	ed[cnt].w=wh;
}
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int n,m,k;
int a,b,c,ans;
bool q[N];
int dfs()
{
	for(int i=1;i<=2*m;i++)
	{
		if(!q[ed[i].t])
		{
			ans+=ed[i].w;
			q[ed[i].t]=1;
			q[ed[i].fro]=1;
		}
	}
	return ans;	
}
int c2[11];
int c1[11][N];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
		}
	memset(dis,0x3f,sizeof(dis));
	sort(ed+1,ed+2*m+1,cmp);
	dfs();
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c2[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld %lld",&c1[i][j]);
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
