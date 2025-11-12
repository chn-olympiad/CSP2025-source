#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,sum,cnt;
int a[10006][10006],b[11][10006],c[11],ans[2000006];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u][v] = w;
		a[v][u] = w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&b[i][j]);
		}
		for(int j=1;j<=n;j++)
		{
			for(int r=1;r<=n;r++)
			{
				if(j == r) continue;
				a[j][r] = a[r][j] = min(a[j][r],b[i][j]+b[i][r]);
			}
		}
	}
	for(int i=1;i<=n;i++) 
	{
		for(int j=i+1;j<=n;j++) 
		{
			ans[++cnt] = a[i][j];
			printf("%lld %lld %lld\n",i,j,a[i][j]);
		}
	}
	sort(ans+1,ans+1+cnt);
	for(int i=1;i<n;i++) sum += ans[i];
	printf("%lld",sum);
	return 0;
}
/*
4 6 1
1 2 4
1 3 5
1 4 2
2 3 3
2 4 7
3 4 6
0 1 2 10 11
*/
