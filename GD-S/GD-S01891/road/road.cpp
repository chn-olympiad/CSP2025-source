#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+50;
using ll = long long;

int n, m, k, a[N], dis1[N], dis2[N];
bool used[N];// ok[N];
vector<pair<int, int> > g[N];

void dijkstra(int c, int num)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > q;
	q.push({c, num});
	dis1[num] = c;
	
	while(!q.empty())
	{
		int c = q.top().first, u = q.top().second;
//		cout << u << endl;//111
		q.pop();
		
		if(used[u] || dis1[u] < c) continue;
		
		for(auto [v, w] : g[u])
		{
			if(dis1[v] > dis1[u] + w + a[v])
			{
				dis1[v] = dis1[u] + w + a[v];
				dis2[v] = w + a[v];
				//ok[u] = true;
				if(!used[v])
				{
					//used[v] = 1; 
					q.push({dis1[v], v});
				}
			}
			if(u <= n && dis2[v] > w + a[v]) dis2[v] = w + a[v];
		}
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	
	for(int i = 1; i <= m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		a[i] = 0;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	
	for(int i = 1; i <= k; i++)
	{
		cin >> a[n+i];
		for(int j = 1; j <= n; j++)
		{
			int c;
			cin >> c;
			g[n+i].push_back({j, c});
			g[j].push_back({n+i, c});
		}
	}
	
	memset(dis1, 0x3f, sizeof dis1);
	dijkstra(0, 1);
	
	ll ans = 0;
	int maxnn = -1;
	for(int i = 1; i <= n; i++)
	{
		ans += dis2[i];
		maxnn = max(maxnn, dis1[i]);
		cout << dis2[i] <<endl;
	}
	for(int i = 1; i <= k; i++)
	{
		if(dis1[i+n] < maxnn)
		{
			ans += dis2[n+i];
			cout << dis2[n+i] <<endl;
		 } 
	}
	cout << ans;
	return 0;
}
