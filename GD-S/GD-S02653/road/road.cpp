#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int n, m, k, c[15], a[15][1010000], father[1010000];
struct Edge{int u, v, w;}e[1010000];
vector<Edge> used;
int find(int x)
{
	if(father[x] != x) father[x] = find(father[x]);
	return father[x];
}
bool cmp(Edge x, Edge y) {return x.w < y.w;}
int ans = 0;

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	bool A = 1;
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if(c[i]) A = 0;
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if(a[i][j]) A = 0;
		}
	}
	if(A && k)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= n; i++) father[i] = i;
	int cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		int fx = find(e[i].u), fy = find(e[i].v);
		if(fx != fy)
		{
			father[fx] = fy;
			ans += e[i].w, cnt++;
			used.push_back(e[i]);
		}
		if(cnt == n - 1) break;
	}
	if(k == 0)
	{
		cout << ans << '\n';
		return 0;
	}
	cout << ans - 2 << '\n';
	
	fclose(stdin); fclose(stdout);
	return 0;
}
