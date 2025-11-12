#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int NR = 1e4+20;
const int MR = 1e6+10;
int n, m, k;
int u[MR], v[MR], w[MR];
int V[15][NR], tot;
int fa[NR];
int c[NR], a[15][NR], t;
int d[15], p[15], sz;
int p0;
int num[NR];

void init()
{
	for (int i = 1; i <= n + k; i++)
		fa[i] = i, num[i] = 1;
}

int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

bool cmp(int i, int j)
{
	return w[i] < w[j];
}

bool cmp1(int i, int j)
{
	return a[t][i] < a[t][j];
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	vector<int> e;
	e.clear();
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", u + i, v + i, w + i), e.push_back(i);
	sort(e.begin(), e.end(), cmp);
	init();
	for (int i = 0; i < m; i++)
	{
		if (find(u[e[i]]) == find(v[e[i]])) continue;
		V[k][tot++] = e[i];
		fa[find(u[e[i]])] = find(v[e[i]]);
	}
	for (int j = 0; j < k; j++)
	{
		scanf("%d", c + j);
		for (int i = 1; i <= n; i++)
			scanf("%d", a[j] + i), V[j][i - 1] = i;
		t = j;
		sort(V[j], V[j] + n, cmp1);
	}
	long long ans = 9e18;
	for (int msk = 0; msk < (1 << k); msk++)
	{
		sz = 0;
		long long sum = 0;
		for (int j = 0; j < k; j++)
			if ((msk >> j) & 1) 
			{
				d[sz] = j;
				sum += c[j];
				p[sz] = 0;
				sz++;
			}
		p0 = 0;
		init();
		int cnt = 0;
		while (1)
		{
			int wmin = 2e9, j = k, W;
			for (int i = 0; i < sz; i++)
			{
				W = a[d[i]][V[d[i]][p[i]]];
				if (p[i] < n && W < wmin)
					wmin = W, j = i;
			}
			if (p0 < n - 1 && w[V[k][p0]] < wmin)
				wmin = w[V[k][p0]], j = k;
			if (wmin == 2e9) break;
			if (j == k) 
			{
				int J = V[k][p0];
				int X = find(u[J]), Y = find(v[J]);
				if (num[X] > num[Y]) swap(X, Y);
				fa[X] = Y;
				num[Y] += num[X];
				sum += w[J], p0++;
			} 
			else 
			{
				int J = V[d[j]][p[j]];
				int X = find(n + d[j] + 1), Y = find(J);
				if (num[X] > num[Y]) swap(X, Y);
				fa[X] = Y;
				num[Y] += num[X];
				sum += a[d[j]][J], p[j]++;
			}
			cnt++;
			if (cnt >= n + sz - 1) break;
			while (p0 < n - 1 && find(u[V[k][p0]]) == find(v[V[k][p0]])) p0++;
			int F, *z, P;
			for (int i = 0; i < sz; i++)
			{
				F = find(n + d[i] + 1);
				z = V[d[i]], P = p[i];
				while (p[i] < n && F == find(z[P])) P++;
				p[i] = P;
			}
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}