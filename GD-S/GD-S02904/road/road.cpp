#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+10,M=2e6+10,inf=1e18;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f; 
}
bool vis[M];
int n,m,k,a[20][N],c[N],tot,cnt;
struct node{int u,v,w;}e[M],E[M],mp[M];
bool cmp(node x,node y){return x.w<y.w;}
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int kruskal(int op=0)
{
	int res=0;
	if(op)sort(e+1,e+1+m,cmp);
	else sort(E+1,E+1+tot,cmp);
	for(int i=1;i<=cnt;i++)fa[i]=i;
	for(int i=1;i<=(op?m:tot);i++)
	{
		int u=op?e[i].u:E[i].u,v=op?e[i].v:E[i].v,w=op?e[i].w:E[i].w;
		int fu=find(u),fv=find(v);
		if(fu^fv)
		{
			if(op)vis[i]=1;
			res+=w;
			fa[fu]=fv;
		}
	}
	return res;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();cnt=n;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[i].u=u,e[i].v=v,e[i].w=w;
	}
	int ans=kruskal(1);
	for(int i=1;i<=m;i++)if(vis[i])++tot,E[tot]=mp[tot]=e[i];
	int base=0;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();bool flag=0;
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
			if(a[i][j]==0)flag=1;
		}
		if(c[i]>0)flag=0;
		if(flag)base|=(1<<i-1);
	}
	for(int j=1;j<(1<<k);j++)
	{
		if((j&base)!=base)continue;
		int lst=tot,sum=0;cnt=n;
		for(int i=1;i<=k;i++)
		{
			if(!((j>>(i-1))&1))continue;
			++cnt;sum+=c[i];
			for(int v=1;v<=n;v++)
			{
				++tot;
				E[tot].u=cnt,E[tot].v=v,E[tot].w=a[i][v];
			}
		}
		int x=kruskal();
		ans=min(ans,sum+x);
		tot=lst;
		for(int i=1;i<=tot;i++)E[i]=mp[i];
	}
	cout<<ans<<endl;
	return 0;
}
/*
*/
