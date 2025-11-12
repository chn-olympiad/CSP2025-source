#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e4 + 5, MAXM = 1e6 + 5;

struct edge
{
	int from, to; ll val;
}e[MAXM];

int k, m, n, a[15][MAXN], c[15], fa[MAXN];

int get_r(int x)
{
	if (fa[x] == x) return x; return fa[x] = get_r(fa[x]);
}

void merge(int x, int y)
{
	int rx = get_r(x), ry = get_r(y); fa[rx] = ry;
}

bool cmp(edge a, edge b)
{
	return a.val < b.val;
}

ll Kruscal(int tar)
{
	sort(e + 1, e + m + 1, cmp); int ans = 0; ll cnt = 0;
	
	for (int i = 1; i <= m; i ++)
	{
		int u = e[i].from, v = e[i].to; ll w = e[i].val;
		
		int ru = get_r(u), rv = get_r(v);
		
		if (ru == rv) continue; merge(ru, rv); ans ++; cnt += w;
		
		if (ans == tar - 1) return cnt;
	}
	
	return -1;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i ++) fa[i] = i;
	
	for (int i = 1; i <= m; i ++)
	{
		int u, v; ll w; cin >> u >> v >> w;
		
		e[i].from = u, e[i].to = v, e[i].val = w;
	}
	
	for (int i = 1; i <= k; i ++)
	{
		cin >> c[i]; for (int j = 1; j <= n; j ++) cin >> a[j][n];
	}
	
	cout << Kruscal(n);
	
	return 0;
}
