#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,k,ans;
int mapp[10100][10100];
int mapk[11][10100],vis_mk[11][10100],kw[11],vis_k[11];
int tot=0;
struct num{
	int u,v,w,k=0;
}a[1000000];
void ad(int u,int v,int w,int k)
{
	tot++;
	a[tot].u=u;
	a[tot].v=v;
	a[tot].w=w;
	a[tot].k=k;
}
int fa[10100];
void init()
{
	for(int p=1;p<=k;p++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i)continue;
				mapp[i][j]=min(mapp[i][j],kw[p]+mapk[p][i]+mapk[p][j]);
			}
		}
	}
}
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool cmp(num x,num y)
{
	return x.w<y.w;
}
int dis[10100];
void dfs()
{
	int toto=0;
	for(int i=1;i<=tot;i++)
	{
		if(toto==n-1)return ;
		int u=a[i].u,v=a[i].v;
		int f1=find(u),f2=find(v);
		if(f1==f2)continue;
		else
		{
			fa[f2]=f1;
			toto++;
			ans+=a[i].w;
			mapp[u][v]=mapp[v][u]==a[i].w;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
//		mapp[u][v]=mapp[v][u]=w;
		ad(u,v,w,0);
		ad(v,u,w,0);
	}
	for(int i=1;i<=k;i++)
	{
		int ant=ans;
		scanf("%d",&kw[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&mapk[i][j]);
		}
	}
	init();
	memset(mapp,INF,sizeof(mapp));
	memset(vis_k,0,sizeof(vis_k));
	memset(vis_mk,0,sizeof(vis_mk));
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+tot+1,cmp);
	dfs();
	printf("%d",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
*/
