#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 2;

struct node
{
	int u, v, w;
};

bool cmp(node a, node b)
{
	return a.w < b.w;
}

vector<int> ds(N);

void init_set()
{
	for (int i = 0; i < N; i++)
	{
		ds[i] = i;
	}
}

int find_set(int p)
{
	if (ds[p] == p) return p;
	ds[p] = find_set(ds[p]);
	return find_set(ds[p]);
}

void merge(int u, int v)
{
	u = find_set(u);
	v = find_set(v);
	ds[u] = ds[v];
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<node> edge;
	for (int i = 0; i < m; i++)
	{
		node x;
		cin >> x.u >> x.v >> x.w;
		edge.push_back(x);
	}
	
	int c[k] = {0};
	int a[k][n] = {0};
	for (int i = 0; i < k; i++)
	{
		cin >> c[i];
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	init_set();
	int ans = 0;
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 0; i < m; i++)
	{
		if (find_set(edge[i].u) != find_set(edge[i].v))
		{
			merge(edge[i].u, edge[i].v);
			ans += edge[i].w;
		}
	}
	cout << ans;
	return 0;
}
