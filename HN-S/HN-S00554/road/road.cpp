#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 15, M = 1.2e6 + 5;
int n, n2, m, m2, k, c[11][N], f[N];
long long num, ans = 1e18;
bool A = 0;
struct node
{
	int u, v, s;
}a[M], b[M];
bool cmp(node a, node b)
{
	return a.s < b.s || (a.s == b.s && a.v < b.v); 
}
int find(int k)
{
	if (f[k] == k)
	{
		return k;
	}
	return f[k] = find(f[k]);
}
void work()
{
	for (int i = 1;i <= n;i++)
	{
		f[i] = i;
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1;i <= m;i++)
	{
		if (find(a[i].u) != find(a[i].v))
		{
			num += a[i].s;
			f[find(a[i].u)] = f[find(a[i].v)];
		}
	}
	ans = min(ans, num);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	n2 = n, m2 = m;
	for (int i = 1;i <= m;i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].s;
		if (a[i].u > a[i].v)
		{
			swap(a[i].u, a[i].v);
		}
		b[i] = a[i];
	}
	for (int i = 1;i <= k;i++)
	{
		for (int j = 0;j <= n;j++)
		{
			cin >> c[i][j];
		}
		A |= c[i][0];
	}
	if (!A)
	{
		for (int i = 1;i <= k;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				a[++m] = {j, n + i, c[i][j]};
			}
		}
		n += k;
		work();
		cout << ans;
		return 0;
	}
	for (int g = 0;g <= (1 << k) - 1;g++)
	{
		n = n2, m = m2;
		num = 0;
		for (int i = 1;i <= m;i++)
		{
			a[i] = b[i];
		}
		for (int i = 1;i <= k;i++)
		{
			if ((g >> i - 1) & 1)
			{
				n++;
				num += c[i][0];
				for (int j = 1;j <= n2;j++)
				{
					a[++m] = {j, n2 + i, c[i][j]};
				}
			}
		}
		work();
		memset(f, 0, sizeof(f));
	}
	cout << ans;
	return 0;
}
