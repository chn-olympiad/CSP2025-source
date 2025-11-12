#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;

inline void read(int &x)
{
	int f=1; x=0;
	char ch=getchar();
	while (ch<'0' || ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9')
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x*=f;
}
int n,m,k,dist[10005],cnt,c[15][10005],f[15];
vector<vector<pair<int,int> > > g(10005);
struct node
{
	int v,w,city;
	bool operator < (const node &other) const {return w>other.w;}
};
int dijkstra(int t)
{
	memset(dist,0x3f,sizeof(dist));
	priority_queue<node> q;
	q.push({t,0,0});
	dist[t]=0;
	while (!q.empty())
	{
		int nv=q.top().v,nw=q.top().w,ncity=q.top().city;
		q.pop();
		if (cnt==n) return nw;
		for (auto edge:g[nv])
		{
			if (dist[nv]+edge.y<dist[edge.x])
			{
				if (dist[edge.x]>1e13) cnt++;
				dist[edge.x]=dist[nv]+edge.y;
				q.push({edge.x,dist[edge.x],ncity});
			}
		}
		if (ncity<k)
		{
			for (int i=1;i<=k;i++)
			{
				for (int j=1;j<=n;j++)
				{
					if (dist[nv]+c[i][j]<dist[j])
					{
						dist[j]=dist[nv]+c[i][j];
						q.push({j,dist[j],ncity+1});
					}
				}
			}
		}
	}
	return 0x3f3f3f3f3f3f3f3f;
}
signed main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	int u,v,w;
	while (m--)
	{
		read(u),read(v),read(w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for (int i=1;i<=k;i++)
	{
		read(f[i]);
		for (int j=1;j<=n;j++)
			read(c[i][j]),c[i][j]+=f[i];
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=min(ans,dijkstra(i));
	cout << ans;
	return 0;
}
