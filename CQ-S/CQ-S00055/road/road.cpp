//No one cares you else yourself.
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, k;
int val[N][N];
bool vis[N];
struct node
{
	int id;
	int val;
	operator < (const node& other) const
	{
		return other.val < val;
	}
};
int sum = 0;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	vector<int> graph[N];
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(v);
		graph[v].push_back(u);
		val[u][v] = val[v][u] = w;
	}
	priority_queue<node> q;
	q.push({1, 0});
	while (!q.empty())
	{
		node front = q.top();
		vis[front.id] = true;
		sum++;
		q.pop();
		if (sum == n)
		{
			cout << front.val << "\n";
			return 0;
		}
		for (auto it : graph[front.id])
		{
			if (!vis[it])
			{
				q.push({it, front.val + val[front.id][it]});
			}
		}
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
