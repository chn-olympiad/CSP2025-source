#include<bits/stdc++.h>
using namespace std;

bool flag;
int n, m, k, c[12], a[12][1005],p[1005][1005], ans,ans2;
int fa[1005],v ,u ,w;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		fa[i]=i;
	}
	for(int i = 1; i <= m; i++)
	{
		cin >> v >> u >> w;
		p[v][u] = p[u][v] = min(w,p[u][v]);
		
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		int num = c[i];
		for(int j = 1; j <= n; i++)
		{
			cin >> a[i][j];
			num += a[i][j];
		}
		ans = min (num,ans);
	}

	cout << ans;
}
