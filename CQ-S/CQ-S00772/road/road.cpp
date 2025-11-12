#include<bits/stdc++.h>
using namespace std;
namespace hqk{
	int n, m, k, t, c[15], v[15], p[50005], e[15][50005];
	long long s, d;
	struct ee{
		int x, y, z;
	}a[3000005], b[3000005];
	bool o(ee u, ee v)
	{
		return u.z < v.z;
	}
	int get(int x)
	{
		if (x != p[x])
		{
			p[x] = get(p[x]);
		}
		return p[x];
	}
	void dfs(int x)
	{
		if (x > k)
		{
			d = 0;
			m = t;
			for (int i = 1; i <= m; i++)
			{
				a[i] = b[i];
			}
			for (int i = 1; i <= k; i++)
			{
				if (v[i] == 1)
				{
					d += c[i];
					for (int j = 1; j <= n; j++)
					{
						m++;
						a[m].x = i + n;
						a[m].y = j;
						a[m].z = e[i][j];
					}
				}
			}
			for (int i = 1; i <= n + k; i++)
			{
				p[i] = i;
			}
			sort(a + 1, a + m + 1, o);
			for (int i = 1; i <= m; i++)
			{
				int x = get(a[i].x), y = get(a[i].y);
				if (x != y)
				{
					p[x] = y;
					d = d + a[i].z;
				}
			}
			s = min(s, d);
			return ;
		}
		v[x] = 1;
		dfs(x + 1);
		v[x] = 0;
		dfs(x + 1);
	}
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n >> m >> k;
		for (int i = 1; i <= m; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sort(a + 1, a + m + 1, o);
		for (int i = 1; i <= n; i++)
		{
			p[i] = i;
		}
		for (int i = 1; i <= m; i++)
		{
			int x = get(a[i].x), y = get(a[i].y);
			if (x != y)
			{
				p[x] = y;
				t++;
				b[t] = a[i];
				s = s + a[i].z;
			}
		}
		m = t;
		for (int i = 1; i <= m; i++)
		{
			a[i] = b[i];
		}
		for (int q = 1; q <= k; q++)
		{
			cin >> c[q];
			for (int i = 1; i <= n; i++)
			{
				cin >> e[q][i];
			}
		}
		dfs(1);
		cout << s;
		return 0;
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	return hqk::main();
}
