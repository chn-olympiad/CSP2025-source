#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+9,INF=1e17;
int n,m,k,cnt,ans=INF,fa[N],c[N];
bool vis[N];
struct edge
{
	int x,y,z,id;
	bool operator<(const edge b)
	{
		return z<b.z;
	}
}e[N];
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int work(int ge)
{
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int ans=0,ci=0;
	for(int i=1;i<=cnt;i++)
	{
		if(!vis[e[i].id])continue;
		int fx=find(e[i].x),fy=find(e[i].y);
		if(fx!=fy)
		{
			fa[fy]=fx;
			ci++;ans+=e[i].z;
			if(ci==n-1+ge)break;
		}
	}
	return ans;
}
void yu()
{
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int ans=0,ci=0,t=0;
	for(int i=1;i<=cnt;i++)
	{
		if(!vis[e[i].id])continue;
		int fx=find(e[i].x),fy=find(e[i].y);
		if(fx!=fy)
		{
			e[++t]=e[i];
			fa[fy]=fx;
			ci++;ans+=e[i].z;
			if(ci==n-1)break;
		}
	}
	cnt=t;
}
void dfs(int x,int z,int ge)
{
	if(x==k+1)
	{
		ans=min(ans,work(ge)+z);return;
	}
	dfs(x+1,z,ge);
	vis[x]=1;
	dfs(x+1,z+c[x],ge+1);
	vis[x]=0;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	vis[0]=1;
	for(int x,y,z,i=1;i<=m;i++)
		cin>>e[i].x>>e[i].y>>e[i].z,e[i].id=0;
	yu();
	cnt=m;
	for(int a,i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>e[++cnt].z;e[cnt].id=i;
			e[cnt].x=i+n;e[cnt].y=j;
		}
	}
	sort(e+1,e+1+cnt);
	dfs(1,0,0);
//	vis[1]=1;
//	cout<<cdq(1,n)+1;
	cout<<ans;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

