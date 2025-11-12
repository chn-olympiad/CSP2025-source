#include<bits/stdc++.h> 
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10; 
struct EDGE{
	int u, v, w;
}edge[M];
struct node{
	int v, w, id;
};
int n, m, k, c[N], f[N];
long long sum, ans, dis[1005][1005], a[11][N];
vector<node> e[N];
bitset<1005> bs[1005];
int w[N];
int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
} 
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		sum += w;
		dis[u][v] = w;
		edge[i] = ((EDGE){u, v, w});
	}
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	if(k == 0) {
		printf("%lld", sum);
		return 0;
	}
	for(int i = 1; i <= n; i++) f[i] = i, bs[i][i] = 1;
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(a[i][j] != 0) continue;
			int ri = find(i), rj = find(j);
			if(ri != rj) f[rj] = ri, bs[ri] = (bs[ri] & bs[rj]);
			w[ri] = i;
		}
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			long long res = 0;
			int ri = find(i), rj = find(j);
			if(ri == rj) continue;
			for(int k = 1; k <= n; k++)
			{
				for(int h = 1; h <= n; h++)
					if(bs[i][k] == 1 && bs[j][h] == 1)
						res = min(res, dis[k][h]);
			}
			for(int h = 1; h <= n; h++)
				if(bs[j][h] == 1)
					res = min(res, a[w[i]][h]);	
			for(int k = 1; k <= n; k++)
				if(bs[i][k] == 1)
					res = min(res, a[w[j]][k]);
			ans += res;
		}
	}
	printf("%lld", ans);
	return 0;
}
