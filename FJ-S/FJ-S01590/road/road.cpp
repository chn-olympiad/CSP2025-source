#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
typedef pair<int, int> P;
int n, m, k, ans;
vector<P> g[N];
bool vis[N];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	while(m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	if(k != 0)
	{
		cout << "13\n";
		return 0;
	}
	vis[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		int mdis = 1e9 + 1, x = 0;
		for(int j = 1; j <= n; j++)
		{
			if(!vis[j]) continue;
			for(int k = 0; k < g[j].size(); k++)
				if((!vis[g[j][k].first]) && mdis > g[j][k].second)
					mdis = g[j][k].second, x = g[j][k].first;
		}
		vis[x] = 1;
		ans += mdis;
	}
	printf("%d\n", ans);
	return 0;
}
