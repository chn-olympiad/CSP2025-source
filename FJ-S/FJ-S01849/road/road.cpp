#include <iostream>
#include <algorithm>
using namespace std;

int parent[100010];
long long c[10010][20], pri[20];
bool f[10010][10010];
int n, m, k;

struct Road
{
	int u, v;
	long long w;
} a[10010];

bool cmp(Road x, Road y)
{
	return x.w < y.w;
}

int find(int x)
{
	if (parent[x] == x) return x;
	return find(parent[x]);
}

void hebin(int x, int y)
{
	int rx = find(x);
	int ry = find(y);
	if (rx != ry) parent[rx] = ry;
	return;
}

bool check()
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (parent[i] == i) sum++;
	if (sum <= 1) return true;
	return false;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> pri[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n - 1; j++)
		{
			for (int l = j + 1; l <= n; l++)
			{
				m++;
				a[m].u = j;
				a[m].v = l;
				a[m].w = c[i][j] + c[i][l];
			}
		}
	}
	sort(a + 1, a + 1 + m, cmp);
	long long ans = 0;
	for (int i = 1; i <= m; i++)
	{
		if (f[a[i].u][a[i].v]) continue;
		hebin(a[i].u, a[i].v);
		f[a[i].u][a[i].v] = true;
		ans += a[i].w;
		if (check())
		{
			cout << ans << endl;
			break;
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
