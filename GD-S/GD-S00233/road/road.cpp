#include<bits/stdc++.h>
using namespace std;
const long long M = 4e6 + 10;
const long long N = 1e5 + 10;
const long long N_1 = 1e3 + 10; 
const long long K = 15;
const int MAX = 1e9 + 10;
int n , m , k;
struct edge{
	long long u , v , w , id;
}g[M];
bool cmp(edge x , edge y)
{
	return x.w < y.w;
}
long long c[K];
long long  a[K][N];
long long fa[N];
inline long long find(long long x)
{
	if (fa[x] != x)
	{
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
long long ans;
bool vis[20];
long long maxn = 0;
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> g[i].u >> g[i].v >> g[i].w;
		g[i].id = -1;
		maxn = max(maxn , g[i].w);
	}
	for (int i = 1; i <= k; ++i)
	{
		cin >> c[i];
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
			for (int o = j - 1; o >= 1; --o)
			{
				g[++m].u = j;
				g[m].v = o;
				g[m].w = a[i][j] + a[i][o];
				g[m].id = i;
				maxn = max(maxn , g[m].w);
			}
		}
	}
	sort(g + 1 , g + 1 + m , cmp);
//	for (int i = 1; i <= m; ++i)
//	{
//		cout << g[i].u << " " << g[i].v << ' ' << g[i].w << endl;
//	}
	for (int i = 1; i <= m; ++i)
	{
		int u = find(g[i].u);
		int v = find(g[i].v);
		if (fa[u] == fa[v])
		{
			continue;
		}
		if (g[i].id != -1)
		{
			if (c[g[i].id] >= maxn)
			{
				continue;
			}
			if (!vis[g[i].id])
			{
				ans += c[g[i].id];
			}
			vis[g[i].id] = true;
		}
		fa[find(u)] = fa[find(v)];
		ans += g[i].w;
	}
	cout << ans;
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
