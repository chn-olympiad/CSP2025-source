#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct Edge
{
	long long v, w;
	bool pass;
};
struct Point
{
	long long v, dis;
	bool operator < (const Point x) const
	{
		return dis > x.dis;
	}
};
priority_queue<Point> q;
vector<Edge> e[MAXN];
int n, m, k, u[MAXN], v[MAXN];
long long w[MAXN], c[MAXN], ans;
bool flag[MAXN];
void dfst(int s)
{
	flag[s] = true;
	for (int i = 0; i < e[s].size(); i++)
	{
		if (!e[s][i].pass)
		{
			e[s][i].pass = true;
			q.push((Point){e[s][i].v, e[s][i].w});
		}
	}
	while(!q.empty())
	{
		Point nt = q.top();
		q.pop();
		if (flag[nt.v])
			continue;
		ans += nt.dis;
		dfst(nt.v);
	}
}
void AddEdge(int u, int v, long long w)
{
	e[u].push_back((Edge){v, w, false});
	e[v].push_back((Edge){u, w, false});
}
int main()
{
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		AddEdge(u[i], v[i], w[i]);
	}
	for (int i = 1; i <= k; i++)
	{
		long long a;
		cin >> c[i];
		for (int j = 1; j <= m; j++)
		{
			cin >> a;
			if (i != j)
				AddEdge(i, j, a + c[i]);
		}
	}
	dfst(1);
	cout << ans;
	return 0;
}

