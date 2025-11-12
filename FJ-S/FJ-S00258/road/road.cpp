#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
typedef long long ll;
int n,m,K;
struct Edge{
	int x,y;
	ll z;
	int a;
	bool operator < (const Edge &x) const
	{
		return z>x.z;
	}
}eg[M];
int f[N],siz[N];
bool flag[15];
bool vis[N];
ll ans;
ll c[15],a[15][N],A[15];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	x=find(x); y=find(y);
	if(siz[x]<siz[y]) swap(x,y);
	siz[x]+=siz[y];
	f[y]=f[x];
}
bool check()
{
	for(int i=1;i<=K;i++)
		if(!flag[i]) return 0;
	return 1;
}
bool cmp(Edge x,Edge y)
{
	return x.z<y.z;
}
void solve1()
{
	sort(eg+1,eg+m+1,cmp);
	for(int i=1;i<=n;i++)
		f[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++)
	{
		int x=eg[i].x,y=eg[i].y; ll z=eg[i].z;
		x=find(x); y=find(y);
		if(x==y) continue;
		ans+=z;
		merge(x,y);
	}
	printf("%lld",ans);
}
void solve2()
{
	for(int i=1;i<=K;i++)
	{
		for(int j=1;j<=n;j++)
			if(!a[i][j])
			{
				for(int k=1;k<=n;k++)
					eg[++m]={j,k,a[i][k]};
				break;
			}
	}
	solve1();
}
ll krusal()
{
	ll res=0;
	for(int i=1;i<=m;i++)
	{
		int x=eg[i].x,y=eg[i].y; ll z=eg[i].z;
		x=find(x); y=find(y);
		if(x==y || !vis[eg[i].a]) continue;
		res+=z;
		merge(x,y);
	}
	return res;
}
void dfs(int k)
{
	if(k>n) return;
	vis[k]=1;
	ans=min(ans,krusal());
	dfs(k+1);
	vis[k]=0;
	ans=min(ans,krusal());
	dfs(k+1);
}
void solve3()
{
	ans=1e10;
	for(int i=1;i<=K;i++)
	{
		for(int j=1;j<=n;j++)
			eg[++m]={i,j,a[i][j],i};
	}
	dfs(1);
	printf("%lld",ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++)
	{
		int x,y; ll z;
		cin>>x>>y>>z;
		eg[i]={x,y,z};
	}
	for(int i=1;i<=K;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(!a[i][j]) flag[i]=1;
		}
		if(c[i]) flag[i]=0;
	}
	if(!K)
	{
		solve1();
		return 0;
	}
	if(check())
	{
		solve2();
		return 0;
	}
	if(n<=1000)
	{
		solve3();
		return 0;
	}
	for(int i=1;i<=n+K;i++)
		f[i]=i,siz[i]=1;
	priority_queue <Edge> q,s[15];
	for(int i=1;i<=K;i++)
		for(int j=1;j<=n;j++)
			s[i].push({i+n,j,a[i][j],0});
	for(int i=1;i<=m;i++)
		q.push({eg[i].x,eg[i].y,eg[i].z,0});
	for(int i=1;i<=n+K-1;i++)
	{
		Edge minx={0,0,1000000001,0}; int minn=0;
		for(int i=1;i<=K;i++)
		{
			while(!s[i].empty())
			{
				Edge k=s[i].top();
				if(find(k.x)==find(k.y)) s[i].pop();
				else
				{
					if(k.z<minx.z)
					{
						minn=i;
						minx=k;
					}
					break;
				}
			}
		}
		while(!q.empty())
		{
			Edge k=q.top();
			if(find(k.x)==find(k.y)) q.pop();
			else
			{
				if(k.z<=minx.z)
				{
					minn=0;
					minx=k;
				}
				break;
			}
		}
		int x=minx.x,y=minx.y; ll z=minx.z;
		ans+=z;
		merge(x,y);
		if(!minn) q.pop();
		else s[minn].pop(),A[minn]++;
	}
	for(int i=1;i<=K;i++)
		if(A[i]>1) ans+=c[i];
	printf("%lld",ans);
	return 0;
}
