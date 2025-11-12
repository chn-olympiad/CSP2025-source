#include <bits/stdc++.h>
using namespace std;

namespace ljw
{
	typedef long long ll;
	
	const int N = 5e6 + 10;
	int pre[N];
	int h[N], e[N], ne[N], idx;
	ll w[N], v[N], d[N];
	int n, m, k;
	
	void add(int a, int b, int c)
	{
		e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
	}
	
	struct Cow
	{
		int u;
		ll dist;
		
		inline bool operator< (const Cow &u) const
		{
			return dist < u.dist;
		}
	};
	
	struct Meow
	{
		int x, y, z;
		
		inline bool operator< (const Meow &u) const
		{
			if (x != u.x)
				return x < u.x;
				
			if (y != u.y)
				return y < u.y;
				
			return z < u.z;
		}
	};
	
	void dijkstra(int u)
	{
		priority_queue<Cow> heap;
		
		memset(d, 0x3f, sizeof d);
		
		heap.push({u, 0});
		d[u] = 0;
		
		while (heap.size())
		{
			Cow t = heap.top();
			heap.pop();
			
			int u = t.u;
			
			for (int i = h[u]; ~i; i = ne[i])
			{
				int j = e[i];
				
				if (d[j] > d[u] + w[i])
				{
					pre[j] = u;
					d[j] = d[u] + w[i] + (j > n) * v[j];
					heap.push({j, d[j]});
				}
			}
		}
	}
	
	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
		
		cin >> n >> m >> k;
		
		memset(h, -1, sizeof h);
		
		int a, b, c;
		while (m--)
		{
			cin >> a >> b >> c;
			
			add(a, b, c);
			add(b, a, c);
		}
		
		for (int i = 1; i <= k; i++)
		{
			cin >> v[i + n];
			
			for (int j = 1, p; j <= n; j++)
			{
				cin >> p;
				
				add(i + n, j, p);
			}
		}
		
		dijkstra(1);
		
		set<Meow> s;
		for (int i = 2; i <= n; i++)
		{
			int now = i;
			while (now)
			{
				s.insert({now, pre[now], w[h[now]]});
				now = pre[now];
			}
		}
		
		int res = 0;
		for (auto i : s)
			res += i.z;
		
		cout << res;
		
		
		return 0;
	}
}

int main()
{
	return ljw::main();
}
