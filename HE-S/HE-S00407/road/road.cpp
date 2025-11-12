#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
int n,m,k;
int e[N][N];
bool flag[N];
int a[15][N],c[15];
void solve()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j)
			e[i][j] = 1e9 + 7;
	for(int i = 1,u,v,w;i <= m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		e[u][v] = w;
		e[v][u] = w;
	}
	for(int i = 1;i <= k;++i)
	{
		scanf("%d",c + i);
		for(int j = 1;j <= n;++j)scanf("%d",&a[i][j]);
	}
	for(int i = 1;i <= k;++i)
	{
		for(int j = 1;j <= n;++j)
		{
			for(int l = 1;l <= n;++l)
			{
				if(l == j)
				{
					e[j][l] = 0;
					continue;
				} 
				e[j][l] = min(e[j][l],a[i][j] + a[i][k]);
				e[l][j] = min(e[l][j],a[i][j] + a[i][k]);
			}
		}
	}
	long long ans = 0;
	int i = 1;
	for(int x = 1;x <= n - 1;++x)
	{
		if(flag[i]) continue;
		int cnt = 1e9 + 8,res = 0;
		for(int j = 1;j <= n;++j)
		{
			if(!flag[j] && cnt > e[i][j] && e[i][j] != 1e9 + 7 && i != j)
			{
				cnt = e[i][j];
				res = j;
			}
		}
		flag[i] = 1;
		i = res;
		ans += cnt;
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}

