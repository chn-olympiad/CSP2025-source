#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T>void Min(T &x,T y) { if (y<x) x=y; }
const int MAXK=10,N=10010+MAXK,M=1000010+N*MAXK;
int n,m,K;
struct Edge
{
	int u,v,w;
	bool operator < (const Edge &o) const { return w<o.w; }
} e[M];
int c[MAXK];
int wei[MAXK][N];

int p[N];
int find(int x) { return p[x]==x ? x : (p[x]=find(p[x])); }
bool vis[N];

namespace Subtask
{
	void work()
	{
		int tot=m;
		for (int i=0;i<K;i++) for (int j=1;j<=n;j++) e[++tot]={n+i+1,j,wei[i][j]};
		sort(e+1,e+tot+1); ll ans=0;
		for (int i=1;i<=n+K;i++) p[i]=i;
		for (int i=1;i<=tot;i++)
		{
			Edge t=e[i]; int u=t.u,v=t.v,w=t.w;
			u=find(u),v=find(v);
			if (u!=v)
			{
				p[u]=v;
				ans+=w;
			}
		}
		cout << ans << "\n";
	}
}

namespace Brute
{
	void work()
	{
		ll ans=1e18;
		for (int S=0;S<(1<<K);S++)
		{
			int tot=m;
			ll res=0;
			for (int i=0;i<K;i++)
			{
				if (!(S>>i&1)) continue;
				res+=c[i]; 
				for (int j=1;j<=n;j++) e[++tot]={n+i+1,j,wei[i][j]};
			}
			if (res>=ans) continue;
			for (int i=1;i<=n+K;i++) p[i]=i;
			sort(e+1,e+tot+1);
			for (int i=1;i<=tot;i++)
			{
				Edge t=e[i]; int u=t.u,v=t.v,w=t.w;
				u=find(u), v=find(v);
				if (u!=v)
				{
					p[u]=v;
					res+=w;
				}
			}
			Min(ans,res);
		}
		cout << ans << '\n';
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> K;
	for (int i=1;i<=m;i++)
	{
		int u,v,w; cin >> u >> v >> w;
		e[i]={u,v,w};
	}
	bool flag=true;
	for (int i=0;i<K;i++)
	{
		cin >> c[i];
		for (int j=1;j<=n;j++) cin >> wei[i][j];
		if (c[i]>0) flag=false;
	}
	
	if (flag) Subtask::work();
	else Brute::work();
	
	return 0;
}
