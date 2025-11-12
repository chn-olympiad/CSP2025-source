#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int maxn = 1e9;
vector<pair<int, int> > g[N];
int d[N];
priority_queue<pair<int, int> > q;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		g[u[i]].push_back({v[i], w[i]});
	}
	for(int i = 0; i <= n; i++) d[i] = maxn;
	d[0] = 0;
	
	int p = q.top().second;
	int dd = -q.top().first;
	q.pop();
	for(int i = 0; i < g[x].size() ; i++)
	{
		int y = g[x][i].second;
		int ww = g[x][i].first;
		if(d[y] > d[x] + ww)
		{
			d[y] = d[x] + ww;
			q.push({-s[y], y});
		}
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << d[n] << endl;	
	
	return 0;
}
