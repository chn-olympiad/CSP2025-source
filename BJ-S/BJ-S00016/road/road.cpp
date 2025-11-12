#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define MAXN 10005
#define MAXM 1000005
#define MAXK 13
struct edge {
	int u, v, w, tag;
	edge(int _u = 0, int _v = 0, int _w = 0, int _t = 0)
		: u(_u),
		  v(_v),
		  w(_w),
		  tag(_t) {}
	bool operator<(const edge &other) const {
		return w < other.w;
	}
} final_edges[MAXN * MAXK + MAXN], m_edges[MAXM];
int final_m;
void add_final(int u, int v, int w, int tag)
{
	final_edges[++final_m] = edge(u, v, w, tag);
}
int n, m, k, c[MAXK], a[MAXK][MAXN];
namespace DSU {
	int fa[MAXN + MAXK];
	int getfa(int id)
	{
		return fa[id] == id ? id : (fa[id] = getfa(fa[id]));
	}
	void init(int tot)
	{
		for (int i = 0; i <= tot; i++)
		{
			fa[i] = i;
		}
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> m_edges[i].u >> m_edges[i].v >> m_edges[i].w;
	}
	sort(m_edges + 1, m_edges + m + 1);
	DSU::init(n);
	for (int i = 1; i <= m; i++)
	{
		int u = DSU::getfa(m_edges[i].u);
		int v = DSU::getfa(m_edges[i].v);
		if (u != v)
		{
			DSU::fa[u] = v;
			add_final(m_edges[i].u,
					  m_edges[i].v,
					  m_edges[i].w,
					  -1);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			add_final(i + n,
					  j,
					  a[i][j],
					  i - 1);
		}
	}
	sort(final_edges + 1, final_edges + 1 + final_m);
	ll ans = LLONG_MAX;
	for (int mask = 0; mask < (1 << k); mask++)
	{
		ll now_ans = 0;
		DSU::init(n + k);
		// int need_edge = n + __builtin_popcount(mask) - 1;
		for (int j = 0; j < k; j++)
		{
			if ((mask >> j) & 1)
			{
				now_ans += c[j + 1];
			}
		}
		for (int i = 1; i <= final_m; i++)
		{
			if (!~final_edges[i].tag || ((mask >> final_edges[i].tag) & 1))
			{
				int u = DSU::getfa(final_edges[i].u);
				int v = DSU::getfa(final_edges[i].v);
				if (u != v)
				{
					DSU::fa[u] = v;
					now_ans += final_edges[i].w;
				}
			}
		}
		if (now_ans < ans)
		{
			ans = now_ans;
		}
	}
	cout << ans << '\n';
	return 0;
}

/*

T1 先贪心后反悔，暴力反悔直到合法

T2 先跑 kruskal 找出一颗最小生成树，不管选什么新点，都不会用除了这个生成树以外的原边，可以证，之后暴力枚举新点集合？分治归并排序优化边的排序，O(n * k * 2^k * log(k) * 阿尔法(n))。好像唐了。可以先排好全部 n*k+n-1 条边，每次枚举集合之后扫一遍全部边，O(n * k * 2^k * 阿尔法(n))，n=10010 阿尔法(n)<=5

*/