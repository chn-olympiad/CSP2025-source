# include <bits/stdc++.h>

using namespace std;

const int Max = 1e6 + 5;

int main()
{
	freopen("road.in", "r", stdin);
	
	freopen("road.out", "w", stdout);
	
	int n, m, k;
	
	cin >> n >> m >> k;
	
	vector<vector<int>> grid(n, vector<int>(m, Max));
	
	vector<vector<int>> money(k, vector<int>(n + 1, 0));
	
	int t = m;
	
	while(t--)
	{
		int u, v, w;
		
		cin >> u >> v >> w;
		
		grid[u][v] = w;
		
		grid[v][u] = w;
	}
	
	int pos = 0; 
	
	for(int sh = 0; sh < k; sh++)
	{
		for(int i = 0; i <= n; i++)
		{
			cin >> money[pos][i];
		}
		
		pos++;
	}
	
	pos--;
	
	vector<bool> vis(n + k, false);
	
	vector<int> dist(n + k, Max);
	
	dist[1] = 0;
	
	for(int i = 1; i < n; i++)
	{
		int cur = -1;
		
		int temp = INT_MAX; 
		
		for(int j = 1; j <= n; j++)
		{
			if(dist[j] <= temp && !vis[j])
			{
				temp = dist[j];
				
				cur = j;
			}
		}
		
		vis[cur] = true;
		
		for(int j = 1; j <= n; j++)
		{
			if(!vis[j] && grid[cur][j] < dist[j])
			{
				dist[j] = grid[cur][j];
			}
		}
	}
	
	int sum = 0;
	
	for(int i = 1; i <= n; i++)
	{
		sum += dist[i];
	}
	
	cout << sum << endl;
	
	return 0;
}
