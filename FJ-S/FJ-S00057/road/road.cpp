#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	vector< vector<int> > dis(n, vector<int> (n, -1));
	vector<int> mon_vi(k);
	vector< vector<int> > make(k, vector<int> (n));
 	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = dis[v][u] = w;
	}
	for(int i = 0; i < m; i++)
	{
		int c;
		cin >> c;
		mon_vi[i] = c;
		for(int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			make[i][j] = a;
		}
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
