#include <bits/stdc++.h>
using namespace std;

struct Edge
{
	int u, v, w;
};

Edge edges[1000000];
int arr[10001];

bool cmp(Edge& x, Edge& y)
{
	return x.w < y.w;
}

void init(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		arr[i] = i;
	}
}

int find(int x)
{
	if (arr[x] == x)
	{
		return x;
	}
	
	arr[x] = find(x);
	
	return arr[x];
}

void bing(int x, int y)
{
	arr[find(x)] = arr[find(y)];
}

bool solve(int n)
{
	int k = find(1);
	
	for (int i = 2; i <= n; ++i)
	{
		if (find(i) != k) return false;
	}
	
	return true;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n, m, k;
	
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; ++i)
	{
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	
	int ans = 0;
	
	sort(edges, edges + m, cmp);
	init(n);
	
	for (int i = 0; i < m && !solve(n); ++i)
	{
		ans += edges[i].w;
		
		bing(edges[i].u, edges[i].v);
	}
	
	cout << ans;
	
	return 0;
}
