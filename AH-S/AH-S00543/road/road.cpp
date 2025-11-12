#include<bits/stdc++.h>
using namespace std;

const int N = 2000005;

int n, m, k, cnt, ans;
int f[N];
int ww[N];

struct node
{
	int u, v, w;
}e[N];

bool cmp(node a, node b)
{
	return a.w < b.w;
}

int find(int x)
{
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}

int Union(int a, int b)
{
	int x = find(a), y = find(b);
	if (x == y) return 0;
	else 
	{
		f[y] = x;
		return 1;
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	for (int i = 1; i <= n; i ++) f[i] = i;
	/*for (int i = 1, u; i <= k; i ++)
	{
		scanf("%d", &u);
		for (int j = 1; j <= n; j ++)
		{
			if (j == u) continue;
			e[++ m].u = u;
			e[m].v = j;
			scanf("%d", &e[m].w);
			e[m].w += 
		}
	}*/
	sort(e + 1, e + 1 + m, cmp);
	for (int i = 1; i <= m; i ++)
	{
		int x = e[i].u, y = e[i].v, w = e[i].w;
		if (Union(x, y))
		{
			ans += w;
			cnt ++;
			ww[cnt] = w;
		}
		if (cnt == n - 1) break;
	}
	for (int i = cnt; i >= cnt - k + 1; i --)
	{
		ans -= ww[i];
	}
	cout << ans;
	return 0;
}