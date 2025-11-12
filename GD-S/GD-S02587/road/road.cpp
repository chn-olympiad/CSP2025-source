#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int c[N], a[10][10005], fa[N];

struct edge
{
	int u, v, w;
} e[N], e2[N];

bool cmp(edge x, edge y)
{
	return x.w < y.w;
}

int find(int x)
{
	if (fa[x] != x)
	{
		return find(fa[x]);
	}
	
	return x;
}

void unite(int x, int y)
{
	int xroot = find(x), yroot = find(y);
	
	if (xroot == yroot)
	{
		return;
	}
	
	fa[x] = y;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n, m, k, cnt = 0, res = 0, m2 = 0;
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	
	for (int i = 1; i <= m; i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	sort(e + 1, e + m + 1, cmp);
	
	for (int i = 1; i <= m; i++)
	{
		int x = e[i].u, y = e[i].v, z = e[i].w;
		
		if (find(x) != find(y))
		{
			unite(x, y);
			res += z;
			cnt++;
			m2++;
			e2[m2].u = x;
			e2[m2].v = y;
			e2[m2].w = z;
		}
		
		if (cnt == n - 1)
		{
			break;
		}
	}
	
	if (k <= 0)
	{
		cout << res;
	}
	else
	{
		for (int i = m2; i > 0; i--)
		{
			int x = e2[i].u, y = e2[i].v, z = e2[i].w, mn1, mn2, tmp, tot;
			fa[x] = x;
			
			for (int j = 1; j <= k; j++)
			{
				if (c[j] >= z)
				{
					continue;
				}
				
				mn1 = 1;
				
				for (int l = 2; l <= n; l++)
				{
					if (a[j][l] < a[j][mn1])
					{
						mn1 = j;
					}
				}
				
				bool f = true;
				
				for (int l = 1; l <= n; l++)
				{
					if (l != mn1 && find(l) != find(mn1))
					{
						if (f || a[j][l] < tmp)
						{
							tmp = a[j][l];
						}
					}
				}
				
				if (j == 1)
				{
					tot = c[j] + a[j][mn1] + tmp;
				}
				else
				{
					tot = min(c[j] + a[j][mn1] + tmp, tot);
				}
			}
			
			if (tot < z)
			{
				res = res - z + tot;
			}
			else
			{
				fa[x] = y;
			}
		}
		
		cout << res;
	}
	
	return 0;
}
