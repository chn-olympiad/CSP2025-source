#include<bits/stdc++.h>
#define int long long
#define pii pair <int, int>
#define fi first
#define se second
using namespace std;

const int N = 1e4 + 100, M = 1e6 + 10;

int n, m, k, ans;
int fa[N], val[100];
unordered_map <int, unordered_map <int, int>> mp, vis;

struct Node
{
	int u, v, w;
}a[M], b[M << 1];

bool cmp(Node a, Node b)
{
	return a.w < b.w;
}

int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]); 
}

inline void js(int zt)
{
	int cntt = 0, yy = 0, pos = m, sum = 0;
	for (register int i = 1; i <= k; i++)
	{
		if ((zt >> yy) & 1)
		{
			cntt++;
			sum += val[i];
			if (sum >= ans) return ;
			for (register int j = 1; j <= n; j++) b[++pos].u = n + i, b[pos].v = j, b[pos].w = mp[n + i][j];
		}
		yy++;
	}
	for (register int i = 1; i <= n + k; i++) fa[i] = i;
	sort(b + 1, b + pos + 1, cmp);
	int cnt = 0;
	for (register int i = 1; i <= pos; i++)
	{
		int uu = b[i].u, vv = b[i].v, ww = b[i].w;
		int fu = find(uu), fv = find(vv);
		if (fu == fv) continue;
		fa[fu] = fv;
		sum += ww;
		if (sum >= ans) return ;
		cnt++;
		if (cnt == n + cntt - 1) break;
	}
	ans = min(ans, sum);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	freopen("road2.in", "r", stdin);
//	freopen("1.txt", "w", stdout);
	cin >> n >> m >> k;
	for (register int i = 1; i <= m; i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
		b[i].u = a[i].u, b[i].v = a[i].v, b[i].w = a[i].w;
	}
	sort(a + 1, a + m + 1, cmp);
	for (register int i = 1; i <= n; i++) fa[i] = i;
	int cnt = 0;
	for (register int i = 1; i <= m; i++)
	{
		int uu = a[i].u, vv = a[i].v, ww = a[i].w;
		int fu = find(uu), fv = find(vv);
		if (fu == fv) continue;
		fa[fu] = fv;
		ans += ww;
		cnt++;
		if (cnt == n - 1) break;
	}
	int u = n;
	bool f1 = true;
	for (register int i = 1; i <= k; i++)
	{
		cin >> val[i];
		if (val[i] != 0) f1 = false;
		u++;
		for (register int j = 1; j <= n; j++)
		{
			int ww;
			cin >> ww;
			mp[u][j] = ww;
		}
	}
	if (f1 == false)
	{
		for (register int zt = 0; zt < (1 << k); zt++) js(zt);
		cout << ans << endl;
	}
	else
	{
		int pos = m;
		for (register int i = 1; i <= k; i++)
		{
			for (register int j = 1; j <= n; j++)
			{
				if (mp[n + i][j] == 0)
				{
					for (register int l = 1; l <= n; l++)
					{
						if (j == l) continue;
						pos++;
						a[pos].u = l, a[pos].v = j, a[pos].w = mp[n + i][l]; 
					}
				}
			}
		}
		for (int i = 1; i <= n + k; i++) fa[i] = i;
		sort(a + 1, a + pos + 1, cmp);
		cnt = 0;
		ans = 0;
		for (register int i = 1; i <= pos; i++)
		{
			int uu = a[i].u, vv = a[i].v, ww = a[i].w;
			int fu = find(uu), fv = find(vv);
			if (fu == fv) continue;
			fa[fu] = fv;
			ans += ww;
			cnt++;
			if (cnt == n - 1) break;
		}
		cout << ans << endl;
	}
	return 0;
}
