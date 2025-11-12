#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int T,n,a[N][3],ans,tmp[N];
int dp[210][210][210],f[N][3],g[N][3][3];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		ans = 0;
		bool fA = 1;
		scanf("%lld",&n);
		for(int i = 1;i<=n;i++)
		{
			for(int j = 0;j<=2;j++)
				scanf("%lld",&a[i][j]);
			if(a[i][1]!=0||a[i][2]!=0)
				fA = 0;
		}
		if(n<=200)
		{
			memset(dp,0,sizeof(dp));
			for(int i = 1;i<=n;i++)
				for(int x = 0;x<=min(i,n/2);x++)
					for(int y = 0;y<=min(i-x,n/2);y++)
					{
						int z = i-x-y;
						if(z>n/2)
							continue;
						if(x<n/2)
							dp[i][x+1][y] = max(dp[i][x+1][y],dp[i-1][x][y]+a[i][0]);
						if(y<n/2)
							dp[i][x][y+1] = max(dp[i][x][y+1],dp[i-1][x][y]+a[i][1]);
						if(z<n/2)
							dp[i][x][y] = max(dp[i][x][y],dp[i-1][x][y]+a[i][2]);
						if(i==n)
							ans = max(ans,dp[i][x][y]);
					}
		}
		else if(fA)
		{
			for(int i = 1;i<=n;i++)
				tmp[i] = a[i][0];
			sort(tmp+1,tmp+n+1);
			for(int i = n;i>=n/2+1;i--)
				ans+=tmp[i];
		}
		else
		{
			memset(g,0,sizeof(g));
			for(int i = 1;i<=n;i++)
				for(int j = 0;j<=2;j++)
				{
					f[i][j] = 0;
					for(int k = 0;k<=2;k++)
					{
						if(g[i-1][k][j]>=n/2)
							continue;
						if(f[i][j]<f[i-1][k]+a[i][j])
						{
							f[i][j] = f[i-1][k]+a[i][j];
							for(int id = 0;id<=2;id++)
								g[i][j][id] = g[i-1][k][id];
							g[i][j][j]++;
						}
					}
				}
			ans = max(f[n][0],max(f[n][1],f[n][2]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/
