#include <bits/stdc++.h>
#define filein(x) freopen(x".in", "r", stdin)
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout);
#define files(x) freopen(x".in", "r", stdin), freopen(x".ans", "w", stdout);
template <typename T>
inline T& chkmax(T& a, const T& b){if (a < b) a = b; return a;}
template <typename T>
inline T& chkmin(T& a, const T& b){if (a > b) a = b; return a;}
using namespace std; // my guiding star.
using ll = long long;
using pii = pair<int, int>;
const int N = 1e4 + 5;
int n, m, k, c[N];
struct dsu
{
	int fa[N];
	inline int find(int u){while (u != fa[u]) u = fa[u] = fa[fa[u]]; return u;}
	inline void merge(int u, int v){fa[find(u)] = find(v);}
	inline void init(int n){iota(fa, fa + 1 + n, 0);}
}D;
vector<tuple<int, int, int, int>> o, e;
int main()
{
	file("road");
	scanf("%d%d%d", &n, &m, &k);
	for (int i=0, u, v, w; i<m; i++) scanf("%d%d%d", &u, &v, &w), o.emplace_back(w, u, v, 0);
	stable_sort(o.begin(), o.end()); D.init(n);
	for (auto [w, u, v, _] : o)
	{
		if ((u = D.find(u)) == (v = D.find(v))) continue;
		e.emplace_back(w, u, v, _); D.merge(u, v);
	}
	for (int i=1; i<=k; i++)
	{
		scanf("%d", c+i);
		for (int j=1, w; j<=n; j++) scanf("%d", &w), e.emplace_back(w, n + i, j, i);
	}
	stable_sort(e.begin(), e.end());
	ll ans = LLONG_MAX;
	for (int s=0; s<(1<<k); s++)
	{
		D.init(n + k); ll ovo = 0;
		for (int i=1; i<=k; i++)
			if (s & (1 << (i - 1))) ovo += c[i];
		for (auto [w, u, v, i] : e)
			if (!i || (s & (1 << (i - 1))))
			{
				if ((u = D.find(u)) == (v = D.find(v))) continue;
				ovo += w; D.merge(u, v);
			}
		chkmin(ans, ovo);
	}
	printf("%lld\n", ans);
	return 0;
}
