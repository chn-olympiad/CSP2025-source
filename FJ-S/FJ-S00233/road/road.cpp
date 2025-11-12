#include <cstdio>
#include <algorithm>
#include <vector>
#define N 10015
#define K 15
using namespace std;

const long long inf = 0x3f3f3f3f3f3f3f3f;

int n, m, k, c[K], a[N];
long long ans;
bool used[K];

struct edge
{
	int x, y, z;
	edge (int u, int v, int w) {x = u, y = v, z = w;}
	bool operator < (edge a) {return z < a.z;}
};

vector <edge> E, e;

int read ()
{
	int x = 0; char c = getchar ();
	for (; c < '0' || c > '9'; c = getchar ());
	for (; c >= '0' && c <= '9'; c = getchar ()) x = x * 10 + c - '0';
	return x;
}

struct DSU
{
	int fa[N], siz[N];
	
	void clear (int n)
	{
		for (int i = 1; i <= n; i ++) fa[i] = i, siz[i] = 1;
		return ;
	}
	
	int find (int x) {return fa[x] != x ? fa[x] = find (fa[x]) : x;}
	
	bool unite (int x, int y)
	{
		x = find (x), y = find (y);
		if (x == y) return 0;
		if (siz[x] < siz[y]) swap (x, y);
		return fa[y] = x, siz[x] += siz[y], 1;
	}
} t1;

void dfs (int x, long long now)
{
	if (x > k)
	{
		long long res = now; t1.clear (n + k);
		for (auto u : e)
		{
			if ((u.x <= n || used[u.x - n]) && t1.unite (u.x, u.y)) res += u.z;
		}
		ans = min (ans, res);
		return ;
	}
	dfs (x + 1, now), used[x] = 1, dfs (x + 1, now + c[x]), used[x] = 0;
	return ;
}

int main ()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 1, x, y, z; i <= m; i ++)
	{
		x = read (), y = read (), z = read ();
		E.emplace_back (x, y, z);
	}
	sort (E.begin (), E.end ()), t1.clear (n);
	for (auto u : E)
	{
		if (t1.unite (u.x, u.y)) e.push_back (u);
	}
	for (int i = 1; i <= k; i ++)
	{
		scanf ("%d", &c[i]);
		for (int j = 1; j <= n; j ++)
		{
			scanf ("%d", &a[j]);
			e.emplace_back (n + i, j, a[j]);
		}
	}
	sort (e.begin (), e.end ());
	ans = inf, dfs (1, 0);
	printf ("%lld", ans);
	return 0;
}
