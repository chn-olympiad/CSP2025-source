#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=1e18,c[15],fa[20005],len[15][10005];bool vis[15];
struct st{
	int u,v,w;
}e[1000005],a[1500005];
bool cmp(st x,st y)
{return x.w<y.w;}
int getfa(int x)
{
	if(fa[x]==x)return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
int getans()
{
	int cnt=0,d=n,maxx=m;
	for(int i=0;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		a[i].u=e[i].u;
		a[i].v=e[i].v;
		a[i].w=e[i].w;
	}
	for(int i=1;i<=k;i++)
		if(vis[i]==1)
		{
			d++;
			a[++maxx].u=0;
			a[maxx].v=n+i;
			a[maxx].w=c[i];
			for(int j=1;j<=n;j++)
			{
				a[++maxx].u=n+i;
				a[maxx].v=j;
				a[maxx].w=len[i][j];
			}
		}
	sort(a+1,a+1+maxx,cmp);
	for(int i=1;i<=maxx;i++)
	{
		int u=a[i].u,v=a[i].v;
		int fu=getfa(u),fv=getfa(v);
		if(fu==fv)continue;
		fa[fu]=fv;
		cnt+=a[i].w;
		d--;
		if(d==0)break;
	}
	return cnt;
}
void dfs(int it,int cnt)
{
	if(it>k)
	{
		ans=min(ans,getans());
		return;
	}
	dfs(it+1,cnt);
	if(cnt+c[it]<=ans)
	{
		vis[it]=1;
		dfs(it+1,cnt+c[it]);
		vis[it]=0;
	}
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>len[i][j];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
