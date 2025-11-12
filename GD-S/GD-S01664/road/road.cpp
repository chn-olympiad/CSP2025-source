#include <iostream>
#include <cstdlib>
#include <queue>

#define int long long

const int MAXN = 1e4 + 7;
const int MAXM = 1e6 + 7;
const int MAXK = 13;

struct Edge
{
	int to;
	int len;
	int nxt = 0;
} edges[(MAXM * MAXK) << 1];
int edgeCount = 0;

int head[MAXN];

int n, m, k;
int cost[MAXK];
int road_cost[MAXK][MAXN];

void AddEdge(int u, int v, int w)
{
	edges[++edgeCount].to = v;
	edges[edgeCount].len = w;
	edges[edgeCount].nxt = head[u];
	head[u] = edgeCount;
}

int ans = 0, finished;
bool visited[MAXN];
void Prim()
{
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	
	visited[1] = true;
	for (int e = head[1]; e; e = edges[e].nxt)
	{
		pq.push(std::make_pair(edges[e].len, edges[e].to));
	}
	
	while (finished < n - 1)
	{
		while (visited[pq.top().second]) pq.pop();
		std::pair<int, int> top = pq.top();
		// std::cout << top.second << ' ' << top.first << std::endl;
		pq.pop();
		
		ans += top.first;
		finished++;
		
		int v = top.second;
		visited[v] = true;
		for (int e = head[v]; e; e = edges[e].nxt)
		{
			int w = edges[e].len;
			int k = edges[e].to;
			if (!visited[k])
			{
				pq.push(std::make_pair(w, k));
			}
		}
	}
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		std::cin >> u >> v >> w;
		AddEdge(u, v, w);
		AddEdge(v, u, w);
	}
	
	for (int i = 1; i <= k; i++)
	{
		std::cin >> cost[i];
		for (int j = 1; j <= n; j++)
		{
			std::cin >> road_cost[i][j];
		}
		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				if (a != b)
				{
					AddEdge(a, b, road_cost[i][a] + road_cost[i][b] + cost[i]);
					AddEdge(b, a, road_cost[i][a] + road_cost[i][b] + cost[i]);
				}
			}
		}
	}
	
	Prim();
	
	std::cout << ans << std::endl;
}
