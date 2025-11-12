#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+15,M=2e6+5;
struct node
{
	int x,y,w;
}l[M];
int n,m,k,ans=1e18,c[N],a[15][N],cnt,fa[N],u[M],v[M],t[M];
bool vis[15];
bool cmp(node p,node q)
{
	return p.w<q.w;
}
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y)
		fa[x]=y;
}
void check()
{
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	cnt=m;
	for(int i=1;i<=m;i++)
		l[i].x=u[i],l[i].y=v[i],l[i].w=t[i];
	int o=0,tot=0,sum=0;
	for(int i=1;i<=k;i++)
	{
		if(!vis[i])
			continue;
		o++;
		sum+=c[i];
		for(int j=1;j<=n;j++)
		{
			cnt++;
			l[cnt].x=i+n,l[cnt].y=j,l[cnt].w=a[i][j];
		}
	}
	sort(l+1,l+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int x=l[i].x,y=l[i].y,w=l[i].w;
		if(find(x)==find(y))
			continue;
		tot++,sum+=w,unionn(x,y);
		if(tot==n+o-1)
			break;
	}
	ans=min(ans,sum);
}
void dfs(int cur)
{
	if(cur==k+1)
	{
		check();
		return ;
	}
	dfs(cur+1);
	vis[cur]=1;
	dfs(cur+1);
	vis[cur]=0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>t[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

