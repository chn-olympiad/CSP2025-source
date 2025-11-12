#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair <int, int> PII;
const int N = 1e6 + 5;

int n, m, k;
vector <PII> e[N];
int ans;
int a[N];
int p[N];
struct Edge
{
	int u, v, w;
	bool operator< (const struct Edge &T)
	const {return w > T.w;}
};
priority_queue <Edge> edge;

int find (int x)
{
	if (p[x] != x) return find(p[x]);
	return x;
}

signed main ()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
		edge.push({a, b, c});
		edge.push({b, a, c});
	}
	for (int i = 1; i <= k; i++)
	{
		int temp; cin >> temp;
		for (int j = 1; j <= n; j++)
			cin >> a[j];
		for (int j = 1; j <= n; j++)
			for (int l = 1; l <= n; l++)
			{
				if (j == l) continue;
				e[j].push_back({l, a[j] + a[l]});
				e[l].push_back({j, a[j] + a[l]});
				edge.push({j, l, a[j] + a[l]});
				edge.push({l, j, a[j] + a[l]});
			}
	}
	for (int i = 1; i <= n; i++) p[i] = i;
	int len = 0;
	while (len < n - 1)
	{
		Edge t = edge.top();
		edge.pop();
		int u = t.u, v = t.v, w = t.w;
		int a = find(u), b = find(v);
		if (a != b) p[a] = b, len++, ans += w;
	}
	printf("%lld", ans);
	return 0;
}
