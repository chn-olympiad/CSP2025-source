#include <bits/stdc++.h>
using namespace std;

int n, m, k, c[100005];
int a[1005][1005];
int num;
struct node
{
	int v, w;
};
vector<node> G[1000005];

int main()
{
//	srand(time(0));
//	int pol = rand() % 114514;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		num += w;
		G[u].push_back({v, w});
	}
	for (int j = 1; j <= k; ++j)
	{
		cin >> c[j];
		for (int l = 1; l <= n; ++l)
		{
			cin >> a[j][l];
		}
	}
	
//	cout << pol << ' ';
	cout << num << '\n';
	
	return 0;
}

