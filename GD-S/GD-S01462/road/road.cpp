#include<bits/stdc++.h>
using namespace std;

struct node
{
	long long p, t, len;	
};
node edge[1000005];
int fa[10005];

int find(int x)
{
	if(x == fa[x])	return x;
	return fa[x] = find(fa[x]);
}
bool cmp(node x, node y)
{
	return x.len < y.len;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	if(k == 0)
	{
		for(int i = 1; i <= m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edge[i] = node{a, b, c};
		}
		sort(edge + 1, edge + m + 1, cmp);
		long long ans = 0;
		for(int i = 1; i <= n; i++)	fa[i] = i;
		for(int i = 1; i <= m; i++)
		{
			int x = edge[i].p, y = edge[i].t;
			x = find(x), y = find(y);
			if(x != y)	fa[x] = y;
			else continue;
			ans += edge[i].len;
		}
		cout << ans << endl;
	}
	else cout << 0 << endl;
	return 0;
}
