#include<bits/stdc++.h>
using namespace std;
#define maxn 10001
#define maxm 100001
int n,m,k,ans;
int cnt,dist[maxn],g[maxn][maxn];
bool vis[maxn];
void add(int u,int v,int w)
{
	g[u][v]=min(g[u][v],w);
	g[v][u]=min(g[v][u],w);
}
int in()
{
	char k=getchar();
	int kk=0,f=1;
	while(k<'0'&&k>'9')
	{
		if(k=='-')f=-1;
		k=getchar();
	}
	while(k>='0'&&k<='9')kk=kk*10+k-'0',k=getchar();
	return f*kk;
}
void out(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
	return ;
}
void init()
{
	memset(dist,0x3f,sizeof dist);
}
void prim(int u)
{
	dist[u]=0;
	vis[u]=true;
	for(int i=1;i<=n;i++)
	{
		int v=i,w=g[u][v];
		if(w==0)continue;
		dist[v]=min(dist[v],w);
		int m=INT_MAX,id=0;
		for(int i=1;i<=n;i++)
		{
			if(m>dist[i]&&!vis[i])m=dist[i],id=i;
		}
		if(id==0)return ;
		ans+=m;
		out(w),putchar(' ');
		prim(id);
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in(),m=in(),k=in();
	for(int i=1,u,v,w;i<=m;i++)
	{
		u=in(),v=in(),w=in();
		add(u,v,w);
	}
	for(int i=1,c;i<=k;i++)
	{
		c=in();
		int ci[maxn];
		for(int j=1;j<=n;j++)ci[j]=in();
		for(int u=1;u+1<=n;u++)
		{
			for(int v=u+1;v<=n;v++)
			{
				int w=ci[u]+ci[v]+c;
				add(u,v,w);
			}
		}
	}
	init();
	prim(1);
	out(ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/