#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
int n,m,k;
int tot,ans=1e18;
bool vis[20];
int cost[20],fa[maxn];
struct node
{
	int u,v,w;
	int op;
}edge[maxn];
void init(int x)
{
	for(int i=1;i<=x;i++)fa[i]=i;
}
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void add(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y)fa[x]=y;
}
int solve1(int _n)
{
	_n=n+k;
	init(_n);
	int res=0,cnt=0;
	for(int i=1;i<=tot;i++)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w,op=edge[i].op;
		if(find(u)==find(v))continue;
		if(vis[op]==0)continue;
		cnt++;
		add(u,v);
		res+=w;
		if(cnt>=_n-1)break;
	}
	return res;
}
int solve2(int _n)
{
	_n=n+k;
	init(_n);
	int res=0,cnt=0;
	for(int i=1;i<=tot;i++)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w,op=edge[i].op;
		if(find(u)==find(v))continue;
//		if(vis[op]==0)continue;
		cnt++;
		add(u,v);
		res+=w;
		if(cnt>=_n-1)break;
	}
	return res;
}
void dfs(int x,int sum,int tmp)
{
	if(x>k)
	{
		ans=min(ans,solve1(tmp)+sum);
		return;
	}
	vis[x]=1;
	dfs(x+1,sum+cost[x],tmp+1);
	vis[x]=0;
	dfs(x+1,sum,tmp);
	return;
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	vis[0]=1;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge[++tot].u=x,edge[tot].v=y,edge[tot].w=z;
		edge[tot].op=0;
	}
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		cin>>cost[i];
		sum+=cost[i];
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			edge[++tot].u=n+i;
			edge[tot].v=j;
			edge[tot].w=x;
			edge[tot].op=i;
		}
	}
	sort(edge+1,edge+1+tot,cmp);
//	if(n>)
	if(k<=7)
	{
		dfs(1,0,0);
		cout<<ans;	
	}
	else 
	{
		cout<<solve2(1)+sum;
	}
	return 0;
}
