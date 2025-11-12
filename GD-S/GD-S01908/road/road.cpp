#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1e6 + 5;

int from[MAXN], to[MAXN], dis[MAXN];

int cnt;
int head[MAXN];

struct edge
{
	int to, dis, nxt;
}e[MAXN << 2];

void Add(int u, int v, int w)
{
	e[++cnt] = edge{v, w, head[u]};
	head[u] = cnt;
}

struct que
{
	int pos, dis;
	bool operator < (const que &x) const
	{
		return dis > x.dis;
	}
};

int n, m, k;
int c[15][10005];
bool vis[MAXN];

ll Solve(int x)
{
	cnt = 0;
	memset(head, 0, sizeof(int) * (n + k + 2));
	for (int i = 1; i <= m; i++)
		Add(from[i], to[i], dis[i]), Add(to[i], from[i], dis[i]);
	ll res = 0;
	int cn = n;
	for (int i = 0; i < k; i++)
	{
		if (x & (1 << i))
		{
			cn++;
			res += c[i + 1][0];
			for (int j = 1; j <= n; j++)
				Add(i + n + 1, j, c[i + 1][j]), Add(j, i + n + 1, c[i + 1][j]);
		}
	}
	priority_queue<que> pq;
	pq.push({1, 0});
	memset(vis, false, sizeof(bool) * (n + k + 2));
	int tot = 0;
	while (!pq.empty())
	{
		int u = pq.top().pos, ww = pq.top().dis;
		pq.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		res += ww;
		if (++tot == cn)
			return res;
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].to, w = e[i].dis;
			if (!vis[v])
				pq.push(que{v, w});
		}
	}
	return res;
}

int main()
{
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", from + i, to + i, dis + i);
	bool flg = true;
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &c[i][0]);
		if (c[i][0])
			flg = false;
		bool ff = false;
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", c[i] + j);
			if (!c[i][j])
				ff = true;
		}
		flg &= ff;
	}
	if (flg)
		return printf("%lld\n", Solve((1 << k) - 1)), 0;
	int S = (1 << k);
	ll ans = 1e18;
	for (int i = 0; i < S; i++)
		ans = min(ans, Solve(i));
	printf("%lld\n", ans);
	return 0;
}
