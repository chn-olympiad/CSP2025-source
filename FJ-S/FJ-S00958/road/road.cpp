#include <bits/stdc++.h>
using namespace std;

long long n, m, k, ans = 0, out = 0, tmpn, x[20005], cx[20005];
bool vis[20005];

struct node
{
	int beg, ed; long long dist;
	bool operator <(const node &a) const
	{
		return dist > a.dist;
	}
};
priority_queue <node> q;

struct edge
{
	int to; long long w;
};
vector <edge> e[20005];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	tmpn = n;
	for (int i = 1; i <= m; i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back((edge) {v, w});
		e[v].push_back((edge) {u, w});
	}
	for (int i = 1; i <= k; i ++)
	{
		cin >> x[i];
		for (int j = 1; j <= n; j ++)
		{
			long long w;
			cin >> w;
			e[i + n].push_back((edge) {j, w + x[i]});
			e[j].push_back((edge) {i + n, w + x[i]});
		}	 
	}
	vis[1] = true;
	for (int i = 0; i < e[1].size(); i ++) q.push((node) {1, e[1][i].to, e[1][i].w});
	while (out < tmpn - 1)
	{
		node u;
		do
		{
			u = q.top();
			q.pop();
		}
		while (vis[u.ed]);
		out ++;
		vis[u.ed] = true;
		ans += u.dist;
		if (u.beg > n)
		{
			if (!cx[u.beg - n]) tmpn ++;
			cx[u.beg - n] ++;
		}
		if (u.ed > n)
		{
			if (!cx[u.ed - n]) tmpn ++;
			cx[u.ed - n] ++;
		}
		for (int i = 0; i < e[u.ed].size(); i ++)
		{
			edge v = e[u.ed][i];
			if (vis[v.to]) continue;
			q.push((node) {u.ed, v.to, v.w});
		}
	}
	for (int i = 1; i <= k; i ++)
		if (cx[i] >= 1) ans -= ((cx[i] - 1) * x[i]);
	cout << ans << endl;
	return 0;
}
