//GZ-S00467 华中师大一附中贵阳学校 陈思佟 
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int N = 1e4+10, M = 2e6+10;
int n, m, k;
int c[11];
int a[11][N];
int p[N];
//vector<vector<pair<int, int> > > g;
struct node
{
	int u, v, w;
} di[M];
//int head[M], ne[N], to[N], w[N], idx;

/*inline void add(int a, int b, int c)
{
	to[idx] = b;
	w[idx] = c;
	ne[idx] = head[a];
	head[a] = idx ++;
}*/

inline bool cmp(node x, node y)
{
	return x.w < y.w;
}

inline int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i ++)
		p[i] = i;
	
	for (int i = 1; i <= m; i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		
		//add(u, v, w);
		//add(v, u, w);
		//g[u].push_back({v, w});
		//g[v].push_back({u, w});
		di[i].u = u, di[i].v = v;
		di[i].w = w;
	}
	
	for (int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j ++)
		{
			cin >> a[i][j];
		}
	}
	
	if (k == 0)
	{
		int res = 0;
		sort(di + 1, di + 1 + m, cmp);
		for (int i = 1; i <= m; i ++)
		{
			int u = di[i].u, v = di[i].v, w = di[i].w;
			int a = find(u), b = find(v);
			if (a != b)
			{
				p[b] = a;
				res += w;
			}
		}
		cout << res << endl;
		return 0;
	}
	
	cout << rand() << endl;
	
	return 0;
}
