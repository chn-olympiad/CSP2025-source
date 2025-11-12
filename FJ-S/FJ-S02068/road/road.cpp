#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1005;

int n, m, k;
int u, v, w;
int vll[15][N], vl[15];
int a[N][N], fa[N];
bool vis[20];
int ans = 0;

//窝要上迷惑行为大赏！！！ 
//放弃惹ToT。。。
//图论不能说差,只能说一点都不会ToT
//《想打个并查集结果发现自己不会最短路和最小生成树》
//在这里@czy@qhx
//为什么不来打CSP ToT
//I LOVE CCF FOR EVER!!! 

int fd(int x)
{
	if(fa[x] = x)return x;
	return fa[x] = fd(fa[x]);
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	memset(a, 1e9, sizeof(a));
	
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; i++)fa[i] = i;
	
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		a[u][v] = min(a[u][v], w);
		a[v][u] = a[u][v];
		ans += w;
	}
	
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &vl[i]);
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &vll[i][j]);
			for(int ii = 1; ii <= j; ii++)
			{
				a[ii][j] = min(a[ii][j], vl[i] + vll[i][j] + vll[i][ii]);
				a[j][ii] = a[ii][j];
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
