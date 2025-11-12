#include <bits/stdc++.h>
using namespace std;
int n, m, k, f[10005], ans;
struct node{
	int u, v, d;
}a[1000005];
bool cmp(node s, node f)
{
	return s.d < f.d;
}
int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
		cin >> a[i].u >> a[i].v >> a[i].d;
	for(int i = 1; i <= n; i++)
		f[i] = i;
	for(int i = 1; i <= k; i++)
	{
		int jjj;
		cin >> jjj;
		for(int j = 1; j <= n; j++)
			cin >> jjj;
	}
	sort(a + 1, a + 1 + m, cmp);
	for(int i = 1; i <= m; i++)
	{
		int dx = find(a[i].u), dy = find(a[i].v);
		if(dx == dy)
			continue;
		f[dx] = dy;
		ans += a[i].d;
	}
	cout << ans;
	return 0;
}
