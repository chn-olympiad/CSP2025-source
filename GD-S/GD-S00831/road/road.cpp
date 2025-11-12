#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 5e6+10;
typedef unsigned long long ll;
struct Edge
{
	ll u, v, w;
	int nxt;
	inline bool operator<(const struct Edge& obj)
	{
		return w<obj.w;
	}
} edge[maxn];
int head[maxn];
ll tot, ans=1e11+7;
inline void add(int u, int v, int w)
{
	edge[++tot].v = v;
	edge[tot].u = u;
	edge[tot].w = w;
	edge[tot].nxt = head[u];
	head[u]=tot;
}
int fa[maxn];
int n, m, k;
int c[11], a[11][maxn], d[maxn];

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void solve1(int x, ll b, int h)
{
	if(b>=ans) return;
	if(x==k+1)
	{
		ll ans1=0;
		for(int i=1;i<=n+k;++i)
		{
			fa[i]=i;
		}
		int cnt=0;
		for(int i=1;i<=tot&&cnt<n+h;++i)
		{
			int u=edge[i].u, v=edge[i].v, w=edge[i].w;
			if(u>n&&!d[u]) continue;
			if(v>n&&!d[v]) continue;
			if(find(u)!=find(v))
			{
				fa[find(u)]=find(v);
				ans1+=w;
				cnt++;
			} 
		}
			ans=min(ans1+b, ans);
		return;
	}
	d[x+n]=1;
	solve1(x+1, b+c[x], h+1);
	d[x+n]=0;
	solve1(x+1, b, h);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	for(int i=0;i<m;++i)
	{
		int u, v, w;
		cin>>u>>v>>w;
		add(u, v, w);
		add(v, u, w);
	}
	
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j)
		{
			int x;
			cin>>x;
			add(n+i, j, x);
			add(j, n+i, x);	
		}	
	}
	if(k==0)
	{
		for(int i=1;i<=n+k;++i)
		{
			fa[i]=i;
		}
		sort(edge, edge+2*m);
		ans=0;
		for(int i=1, cnt=0;i<=tot&&cnt<n;++i)
		{
			int u=edge[i].u, v=edge[i].v, w=edge[i].w;
			if(find(u)!=find(v))
			{
				fa[find(u)]=find(v);
				ans+=w;
				cnt++;
			} 
		}
	} else {
		sort(c,c+k);
		sort(edge, edge+2*(m+n*k));
		solve1(1, 0, 0);	
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
} 
