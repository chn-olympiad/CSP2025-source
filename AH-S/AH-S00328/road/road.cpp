#include <set>
#include <fstream>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr size_t buf_size = 32 * 1024;
char in_buf[buf_size], out_buf[buf_size];

struct edge
{
	ll u, v, w;
	friend bool operator < (const edge& lft, const edge& rgt)
	{
			return lft.w < rgt.w;
	}
};

multiset<edge> graph, tmp_gph;
constexpr ll K = 205, N = 100055;
ll n, m, k, u, v, w, ans, pres, c[K], a[K][N], fa[N], vis[N];
inline ll find(ll nd)
{
	if(fa[nd] == nd) return nd;
	return fa[nd] = find(fa[nd]);
}
inline ll kruscal(ll pres, multiset<edge>& gph)
{
	ll ret = pres, les = n;
	for(register ll i = 1; i <= n * 3; ++i)
		fa[i] = i, vis[i] = 1;
	
	for(register const edge& cur : gph)
	{
		if(les == 0)
			return ret;
		ll nowu = cur.u,
			nowv = cur.v,
			noww = cur.w;
		ll fau = find(nowu),
			fav = find(nowv);
		if(fau == fav)
			continue;
		else
		{
			fa[fau] = fav;
			ret += noww;
		}
	}
	return ret;
}
signed main()
{
	ifstream cin("road.in", ios::binary);
	ofstream cout("road.out", ios::binary);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin.rdbuf()->pubsetbuf(in_buf, buf_size);
	cout.rdbuf()->pubsetbuf(out_buf, buf_size);
	
	cin >> n >> m >> k;
	for(register int i = 1; i <= n; ++i)
	{
		cin >> u >> v >> w;
		if(u > v) swap(u, v);
		graph.insert(edge{u, v, w});
		graph.insert(edge{v, u, w});
	}
	for(register ll j = 1; j <= k; ++j)
	{
		cin >> c[j];
		for(int i = 1; i <= n; ++i)
			cin >> a[j][i];
	}
	ans = LLONG_MAX;
	for(register ll st = 0; st < (1 << (k - 1)); ++st)
	{
		pres = 0;
		tmp_gph = graph;
		for(ll bit = 0; bit < k; ++bit)
		{
			if(st & (1 << bit))
			{
				pres += c[bit + 1];
				for(register ll i = 1; i <= n; ++i)
				{
					tmp_gph.insert(edge{i, bit + 1 + n, a[bit + 1][i]});
					tmp_gph.insert(edge{bit + 1 + n, i, a[bit + 1][i]});
				}
			}
		}
		ans = min(ans, kruscal(pres, tmp_gph));
	}
	cout << ans;
}


