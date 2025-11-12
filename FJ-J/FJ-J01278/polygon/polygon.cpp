#include<bits/stdc++.h>
using namespace std;
int n, a[5050], ans, maxx = -1, sum, b[5050], mod = 998244353, c[5050], l, d[1000010];
map<string, int> m;
void dfs(int x, int maxy, string s)
{
	
	for(int i = 1; i <= n; i++)
	{
		if(x > 2 * maxy && maxy > 0 && !m[s]) ans = (ans + 1) % mod, m[s] = 1;
		if(!b[i] && int(s[s.size() - 1]) - 48 <= a[i])
		{
			b[i] = 1;
			dfs(x + a[i], max(maxy, a[i]), s + char(a[i] + 48));
			b[i] = 0;
		}
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), d[a[i]]++;
	sort(a + 1, a + n + 1);
	string p;
	p.clear();
	dfs(0, -1, p);
	for(int i = 1; i <= 1000010; i++) maxx = max(maxx, d[i]);
	cout << ans + maxx - 1;
	return 0;
}
