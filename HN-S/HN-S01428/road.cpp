#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, m, k;
int fa[20011];
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch =getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
struct edge
{
	int u, v, w;
	inline bool operator < (const edge &b)
	const 
	{
		return w < b.w;
	}
} e[1000011];
int c[11];
int a[11][10011];
vector<edge> re;
int ans = LONG_LONG_MAX;
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	for (int i = 1; i <= k; i++)
	{
		c[i] = read();
		for (int j = 1; j <= n; j++)
			a[i][j] = read();
	}
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++)
	{
		int fu = find(e[i].u);
		int fv = find(e[i].v);
		if (fu == fv)
			continue;
		fa[fu] = fv;
		re.push_back(e[i]);
	}
	for (int S = 0; S < (1 << k); S++)
	{
		vector<edge> ne = re;
		int res = 0;
		for (int j = 1; j <= k; j++)
		{
			if (S & (1 << (j - 1)))
			{
				res += c[j];
				for (int i = 1; i <= n; i++)
					ne.push_back({i, n + j, a[j][i]});
			}
		}
		sort(ne.begin(), ne.end());
		for (int i = 1; i <= n + k; i++)
			fa[i] = i;
		for (edge x : ne)
		{
			int fu = find(x.u);
			int fv = find(x.v);
			if (fu == fv)
				continue;
			fa[fu] = fv;
			res += x.w;
		}
		ans = min(ans, res);
	}
	cout << ans;
	return 0;
}

