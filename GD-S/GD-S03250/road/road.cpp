#include <iostream>

#include <cstring>

#include <queue>

#define int long long

using namespace std;

const int N = 1e4 + 5, M = 11;

int G[N][N];

int n, m, b;

int u, v, w;

int a[M][N], c[M];

struct P
{
	int u, d;
	
	bool operator <(const P &m)const
	{
		return d > m.d;
	}
};

priority_queue<P> q;

bool p[N];

int sum;

signed main()
{
	ios::sync_with_stdio(0);
	
	cin.tie(0), cout.tie(0);
	
	freopen("road.in", "r", stdin);
	
	freopen("road.out", "w", stdout);
	
	memset(G, 0x3f, sizeof G);
	
	cin >> n >> m >> b;
	
	for(int i = 1; i <= m; i ++)
	{
		cin >> u >> v >> w;
		
		G[u][v] = w, G[v][u] = w;
	}
	
	for(int i = 1; i <= b; i ++)
	{
		cin >> c[i];
		
		for(int j = 1; j <= n; j ++)
			cin >> a[i][j];
	}
	 
	for(int i = 1; i <= b; i ++)
		for(int j = 1; j <= n; j ++)
			for(int k = j + 1; k <= n; k ++)
				G[j][k] = min(G[j][k], c[i] + a[i][j]+ a[i][k]), G[k][j] = G[j][k];
	
	q.push({1, 0});
	
	int u = 0, d = 0;
	
	while(!q.empty())
	{
		u = q.top().u, d = q.top().d;
		
		q.pop();
		
		if(p[u])
			continue;
		
		p[u] = true;
		
		sum += d;
		
		//cout << d << ' ' << u << ' ' << k << "\n";
		
		for(int i = 1; i <= n; i ++)
			if(!p[i])
				q.push({i, G[u][i]});
		
		//k ++;
	}
	
	cout << sum;
	
	return 0;
}
