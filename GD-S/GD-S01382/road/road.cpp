#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define endl putchar('\n')
using namespace std;
int read()
{
	int sum = 0, f = 1;
	char ch = getchar();
	for (ch;ch < '0' || ch > '9';ch = getchar()) {if (ch == '-') {f = -1;}}
	for (ch;ch >= '0' && ch <= '9';ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * f;
}
void write(int x)
{
	if (x < 10) return putchar(x + '0'), void();
	write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 1e4 + 15, inf = 1e18;
struct Node
{
	int u, v, val;
	bool operator<(Node x)
	const
	{
		return val < x.val;
	}
};
void gmin(int &x, int y)
{
	if (x > y) x = y;
}
int n, m, k, dis[11][N], c[11], fa[N], ans, siz[N], cnt[N];
vector<Node> vec, tow;
int find(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	if (siz[x] < siz[y]) swap(x, y);
	siz[x] += siz[y];
	fa[y] = x;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1;i <= n + k;i++) fa[i] = i, siz[i] = 1;
	for (int i = 1;i <= m;i++)
	{
		int u = read(), v = read(), w = read();
		vec.pb({u, v, w});
	}
	for (int i = 1;i <= k;i++)
	{
		c[i] = read();
		for (int j = 1;j <= n;j++) dis[i][j] = read(), vec.pb({n + i, j, dis[i][j]});
	}
	sort(vec.begin(), vec.end());
	ans = inf;
	for (int zt = 0;zt < (1 << k);zt++)
	{
		int sum = 0;
        for (int i = 1;i <= n + k;i++) fa[i] = i;
		for (int i = 1;i <= k;i++)
		{
			if (zt & (1 << i - 1)) sum += c[i];
		}
		for (auto i : vec)
		{
			int u = find(i.u), v = find(i.v), w = i.val;
			if (i.u > n)
			{
				if ((zt & (1 << (i.u - n - 1))) == 0) continue;
			}
			if (i.v > n)
			{
				if ((zt & (1 << (i.v - n - 1))) == 0) continue;
			}
			if (u == v) continue;
			sum += w;
			merge(u, v);
		}
		ans = min(ans, sum);
	}
	write(ans);
	return 0;
}
