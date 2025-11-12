#include <bits/stdc++.h>
 
using namespace std;
using cint = const int;
using LL = long long;
using cLL = const long long;

#define N 10005
#define M 1000005
#define K 15
#define base 127
#define mod 998244353
#define inf 1000000007

const double eps = 1e-9;
const double PI = acos(-1.0);

int n, m, k;

struct Edge {
	int u, v, w;

	inline bool operator < (const Edge other) const
		{return w < other.w; }
} e[M], ch[N + N * K], tmp[N + N * K];

int fa[N + K];

int find_fa(cint x) {
	return fa[x] == x ? x : fa[x] = find_fa(fa[x]);
};

int sz = 0;
LL ans = 0ll;

int c[K];
int a[K][N];

LL sum = 0;
int add = 0;
void dfs(cint p) {
	if (p == k + 1) {
		for (int i = 1; i <= sz; ++i)
			tmp[i] = ch[i];
		sort(tmp + 1, tmp + sz + 1);
		iota(fa + 1, fa + k + n + 1, 1);
		LL tot = 0;
		for (int i = 1, cnt = add + n - 1; i <= sz; ++i) {
			cint u = find_fa(tmp[i].u);
			cint v = find_fa(tmp[i].v);
			if (u == v)
				continue;
			tot += tmp[i].w;
			fa[u] = v;
			if (--cnt == 0)
				break;
		}
		ans = min(ans, sum + tot);
		return;
	}
	dfs(p + 1);
	//
	++add;
	sum += c[p];
	for (int j = 1; j <= n; ++j)
		ch[++sz] = Edge{n + p, j, a[p][j]};
	dfs(p + 1);
	--add;
	sum -= c[p];
	sz -= n;
	return;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int x, y, z, i = 1; i <= m; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		e[i] = Edge{x, y, z};
	}
	{
		sort(e + 1, e + m + 1);
		iota(fa + 1, fa + n + 1, 1);
		for (int i = 1, cnt = n - 1; i <= m; ++i) {
			cint u = find_fa(e[i].u);
			cint v = find_fa(e[i].v);
			if (u == v)
				continue;
			ans += e[i].w;
			ch[++sz] = e[i];
			fa[u] = v;
			if (--cnt == 0)
				break;
		}
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
	}
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}
