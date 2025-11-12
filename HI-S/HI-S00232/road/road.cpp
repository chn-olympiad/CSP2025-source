#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u;
	int v;
	long long w;
};
long long countryroad[15][10005], cha[15];
vector <node> road;
bool cmp(node a, node b)
{
	return a.w < b.w;
}
int fa[10005];
int findroot(int x)
{
	if(fa[x] == x)return x;
	return findroot(fa[x]);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	 
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++)fa[i] = i;
	node linshi;
	for(int i = 1; i <= m; i ++)
	{
		long long ui, vi, wi;
		scanf("%lld%lld%lld", &ui, &vi, &wi);
		linshi.u = ui;
		linshi.v = vi;
		linshi.w = wi;
		road.push_back(linshi);
	}
	bool A = 1;
	for(int i = 1; i <= k; i ++)
	{
		scanf("%lld", &cha[i]);
		if(cha[i])A = 0;
		for(int j = 1; j <= n; j ++)
		{
			scanf("%lld", &countryroad[i][j]);
			if(countryroad[i][j])A = 0;
		}	
	}
	if(A)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i2 = 1; i2 <= k; i2 ++)
	{
		for(int j = 1; j < n; j ++)
		{
			for(int k = j + 1; k <= n; k ++)
			{
				linshi.u = j;
				linshi.v = k;
				linshi.w = cha[i2] + countryroad[i2][k] + countryroad[i2][j];
				road.push_back(linshi);	
			}
		}
	}
	sort(road.begin(), road.end(), cmp);
	long long ans = 0, cnt = 0;
	for(unsigned int i = 0; i < road.size(); i ++)
	{
		int u = road[i].u, v = road[i].v;
		int rootu = findroot(u), rootv = findroot(v);
		if(rootu != rootv)
		{
			cnt ++;
			fa[rootu] = rootv;
			ans += road[i].w;
		}
		if(cnt == n - 1)break;
	}
	cout << ans << endl;
	return 0;
}
