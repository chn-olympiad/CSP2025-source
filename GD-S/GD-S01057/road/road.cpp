#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

void init__();
const ll INF = LLONG_MAX;
const ll size = 1e7 + 10;
int n, m, k;

vector<int> arr[size];
int val[10010][10010];
bool vis[10010][10010];

void bfs()
{
	queue<vector<int>> q;
	q.push(arr[1]);
//	vis[arr[1].front][0] = true;
	while(!q.empty())
	{
		vector<int> v = q.front();
		q.pop();
		for(auto i : v)
		{
			
		}
	}
}

signed main()
{
	init__();
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		arr[u].push_back(v);
		val[u][v] = w;
	}
	for(int i = m + 1; i <= k; i++)
	{
		int a;
		cin >> a;
		for(int j = 1; j <= n; j++)
		{
			int b;
			cin >> b;
		}
	}
	
	
	
	cout << flush;
	return 0;
}

void init__()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
