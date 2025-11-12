#include <iostream>
#include <queue>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, fa[N], k2, a[N];
long long ans;
int find(int x)
{
	if(x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
struct e
{
	int u, v, w;
	bool operator <(const e& x)const
	{
		return x.w < w;
	}
};
priority_queue<e> q;
void kruskal()
{
	while(k2 < n - 1)
	{
		int u = q.top().u;
		int v = q.top().v;
		int w = q.top().w;
		q.pop();
		int fu = find(u);
		int fv = find(v);
		if(fu == fv)
			continue;
		k2++;
		fa[fu] = fv;
		ans += w;
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++)fa[i] = i;
	for(int i = 1 ; i <= m ; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		q.push(e{u, v, w});
	}
	for(int i = 1 ; i <= k ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
		{
			cin >> a[j];
		}
		for(int j = 1 ; j <= n ; j++)
		{
			for(int l = 1 ; l <= n ; l++)
			{
				if(i == j)continue;
				q.push(e{j, l, a[j] + a[l]});
			}
		}
	}
	kruskal();
	cout << ans << "\n";
	return 0;
}
