#include <bits/stdc++.h>
#define ll long long
#define lll __int128

using namespace std;

namespace Read
{
	void read() {}
	template<class T1, class ...T2>
	void read(T1 &n, T2 &...m)
	{
		char c;
		bool sgn = false;
		while (isdigit(c = getchar()) == false)
			if (c == '-') sgn = true;
		n = c ^ 48;
		while (isdigit(c = getchar()))
			n = n * 10 + (c ^ 48);
		if (sgn) n = -n;
		read(m...);
	}
}

using namespace Read;

namespace Solve
{
	bool mbe;
	
	const int N = 1e4 + 10;

	struct Edge{int v, w;};
	vector<Edge> G[N + 5];
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	ll sum[N + 5];
	int add[N + 5], dg[N + 5];
	bool vis[N + 5];
	
	void Sol()
	{
		ll ans = 0;
		
		int n, m, k;
		read(n, m, k);
		
		for (int i = 1; i <= m; ++i)
		{
			int u, v, w;
			read(u, v, w);
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}
		for (int i = 1; i <= k; ++i)
		{
			read(add[i + n]);
			int w;
			for (int j = 1; j <= n; ++j)
			{
				read(w);
				G[j].push_back({i + n, w});
				G[i + n].push_back({j, w});
			}
		}
		
		q.push({0, {0, 1}});
		while (q.empty() == false)
		{
			pair<int, pair<int, int>> cur = q.top();
			q.pop();
			int u = cur.second.second;
			if (vis[u]) continue;
			vis[u] = true, add[u] = 0;
			ans += cur.first;
			sum[u] += cur.first;
			++dg[cur.second.first];
			++dg[cur.second.second];
			for (Edge &e : G[u])
			{
				int v = e.v, w = e.w + add[e.v];
				if (vis[v] == false) q.push({w, {u, v}});
			}
		}
		
		for (int i = 1; i <= k; ++i)
			if (dg[i + n] < 2) ans -= sum[i + n];
		
		printf("%lld\n", ans);
	}
	
	bool med;
}

using namespace Solve;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	Sol();
	return 0;
}
