#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

const int N = 1e4 + 10, M = 1e6 + 10, K = 20;
int n, m, k, tot, pre[N + K];
ll a[K][N];
struct E
{
	int from, to;
	ll weight;
} edge[M << 1];

int find(int x)
{
	if (pre[x] == x)
		return x;
	return pre[x] = find(pre[x]);
}
void unionn(int x, int y)
{
	pre[find(y)] = find(x);
}

bool cmp(E x, E y)
{
	return x.weight < y.weight;
}

ll Kruskal()
{
	sort(edge + 1, edge + tot + 1, cmp);
	int cnt = 0;
	ll ans = 0;
	for (int i = 1; i <= tot; i++)
	{
		int u = edge[i].from, v = edge[i].to;
		if (find(u) ^ find(v))
		{
			unionn(u, v), ans += edge[i].weight;
			if (++cnt == n - 1)
				break;
		}
	}
	return ans;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> edge[++tot].from >> edge[tot].to >> edge[tot].weight;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= n; j++)
			cin >> a[i][j];
	int t = n;
	bool flag;
	for (int i = 1; i <= k; i++)
	{
		flag = false;
		for (int j = 1; j <= t; j++)
			if (!a[i][j])
			{
				flag = true, n++;
				edge[++tot] = (E){++n, j, a[i][j]};
			}
	}
	for (int i = 1; i <= n; i++)
		pre[i] = i;
	cout << Kruskal();

	return 0;
}

