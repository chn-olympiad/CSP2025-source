#include <bits/stdc++.h>
using namespace std;

long long n, m, k;
vector<pair<long long, long long>> G[1000005];
long long v[200005], s[200005];
long long p[15][200005], x[200005], y[200005], z[200005];
long long ans = INT_MAX;
long long bfs(long long t)
{
	long long u = 0;
	queue<long long> q;
	q.push(t);
	s[t] = 0;
	while (!q.empty())
	{
		long long w = q.front();
		q.pop();
		for (auto y : G[w])
		{
			if (s[y.second] == INT_MAX)
				q.push(y.second);
			s[y.second] = min(s[y.second], y.first);
		}
	}
	for (long long i = 1; i <= n; i++)
		u += s[i];
//		cout << s[i] << ' ';
//	cout << '\n';
	return u;
}
void dfs(long long i)
{
	if (i == k + 1)
	{
		for (long long j = 1; j <= n; j++)
			s[j] = INT_MAX;
		long long d = 0;
		long long f = n;
		for (long long j = 1; j <= k; j++)
			if (v[j])
			{
				f++;
				for (long long o = 1; o <= n; o++)
					G[f].push_back(make_pair(p[j][o], o)), G[o].push_back(make_pair(p[j][o], f));
				d += p[j][0];
			}
		d += bfs(f);
		for (long long j = 1; j <= n; j++)
			G[j].clear();
		for (long long j = 1; j <= m; j++)
		{
			G[x[j]].push_back(make_pair(z[j], y[j]));
			G[y[j]].push_back(make_pair(z[j], x[j]));
		}
		ans = min(ans, d);
		return;
	}
	v[i] = 1;
	dfs(i + 1);
	v[i] = 0;
	dfs(i + 1);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (long long i = 1; i <= m; i++)
	{
		cin >> x[i] >> y[i] >> z[i];
		G[x[i]].push_back(make_pair(z[i], y[i]));
		G[y[i]].push_back(make_pair(z[i], x[i]));
	}
	int u = 0;
	for (long long i = 1; i <= k; i++)
		for (long long j = 0; j <= n; j++)
			cin >> p[i][j], u += p[i][j];
	if (u == 0)
	{
		cout << 0;
		return 0;
	}
	dfs(1);
	cout << ans;
	
	return 0;
}