#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k;
struct road{
	int v, w;
};
queue<road> roads[10005];

struct town{
	int c;
	int a[10005];
} towns[15];

int f[10005];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		roads[u].push({v, w});
		roads[v].push({u, w});
	}
	
	bool flag = 0;
	for (int i = 1; i <= k; i++)
	{
		cin >> towns[i].c;
		if (towns[i].c != 0) flag = 1;
		for (int j = 1; j <= n; j++)
		{
			cin >> towns[i].a[j];
			if (towns[i].a[j]) flag = 1;
		}
	}
	
	if (!flag)
	{
		cout << 0 << endl;
		return 0;
	}
	
	for (int i = 2; i <= n; i++) f[i] = 1e9;
	
	for (int i = 1; i <= n; i++)
	{
		while(!roads[i].empty())
		{
			road tmp = roads[i].front();
			roads[i].pop();
			f[tmp.v] = min(tmp.w + f[i], f[tmp.v]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += f[i];
	cout << ans << endl;
	return 0;
}

