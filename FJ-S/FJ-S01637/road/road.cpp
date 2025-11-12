#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4 + 5,M = 1e6 + 5;
const ll INF = 1e18;

inline ll read()
{
	ll x = 0,f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-'? -1 : f),c = getchar();
	while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0',c = getchar();
	return x * f;
}

ll n,m,k,c[15],a[15][N];

struct Edge
{
	ll u,v,w;
	bool operator < (Edge x) { return w < x.w; }
};

vector<Edge> G,g;

class Union_Find
{
	private: int f[N + 100];
	public:
		Union_Find() { clear(); }
		void clear() { for(int i = 1; i <= n + k; i++) f[i] = i; }
		inline int find(int x) { return f[x] == x? x : f[x] = find(f[x]); }
		inline void merge(int u,int v)
		{
			int Fu = find(u),Fv = find(v);
			if(Fu != Fv) f[Fv] = Fu;
		}
} UF;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n = read(),m = read(),k = read();
	ll u,v,w;
	for(int i = 1; i <= m; i++) u = read(),v = read(),w = read(),G.push_back({u,v,w});
	for(int i = 1; i <= k; i++)
	{
		c[i] = read();
		for(int j = 1; j <= n; j++) a[i][j] = read();
	}
	sort(G.begin(),G.end());
	
	int tmp = G.size();
	
	vector<Edge> G2; UF.clear(); int Cnt = 0;
	for(Edge E : G) if(UF.find(E.u) != UF.find(E.v) && Cnt < n - 1)
	{
		G2.push_back(E),UF.merge(E.u,E.v);
		if(Cnt >= n - 1) break;
	}
	G = G2; sort(G.begin(),G.end());
	
	ll ans = INF/*,Test = 0*/;
	for(int S = 0; S < (1 << k); S++)
	{
		int cnt = 0; g.clear();
		for(int i = 1; i <= k; i++) if(S >> (i - 1) & 1)
		{
			cnt++;
			for(int j = 1; j <= n; j++)
				g.push_back(Edge({n + i,j,a[i][j]}));
		}
		sort(g.begin(),g.end());
		UF.clear();
		
		ll sum = 0,tot = 0,p = 0;
		for(int i = 1; i <= k; i++) if(S >> (i - 1) & 1) sum += c[i];
		for(Edge E : G) if(UF.find(E.u) != UF.find(E.v))
		{
			while(p < g.size() && g[p].w <= E.w)
			{
//				Test++;
				if(UF.find(g[p].u) != UF.find(g[p].v))
				{
					sum += g[p].w; tot++;
					UF.merge(g[p].u,g[p].v);
					if(tot >= cnt + n - 1) break;
				}
				p++;
			}
//			Test++;
			if(tot >= cnt + n - 1) break;
			if(UF.find(E.u) == UF.find(E.v)) continue;
			sum += E.w; tot++;
			UF.merge(E.u,E.v);
			if(tot >= cnt + n - 1) break;
		}
//		else Test++;
		ans = min(ans,sum);
//		cout << S << " " << sum << endl;
	}
	
	printf("%lld\n",ans);
	
//	cout << Test << endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

