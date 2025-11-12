#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int M = 201;
int dp[M][M][M];
int a[N][4];
int n,ans = 0;
int mx3(int a, int b, int c)
{
	return max(max(a,b),c);
}
//void dfs(int k, int i, int j)
//{
//	dp[k+1][i+1][j] = dp[k][i][j] + a[i][1];
//	dp[k+1][i][j+1] = dp[k][i][j] + a[i][2];
//	dp[k+1][i][j] = dp[k][i][j] + a[i][3];
//	
//}
int cnt,T;
int pf[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		ans = 0;
		memset(dp,0,sizeof(dp));
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
			}
		}
		if(n > 200)
		{
			for(int i = 1; i <= n; i++)
			{
				pf[i] = a[i][1];
			}
			sort(pf+1,pf+n+1);
			for(int i = n/2+1; i <= n; i++)
			{
				ans += pf[i];
			}
			cout << ans << '\n';
			continue;
		}
		for(int i = 0; i <= n/2; i++)
		{
			for(int j = 0; j <= n/2; j++)
			{
				for(int k = 0; k <= n/2; k++)
				{
					cnt = i+j+k;
					if(cnt > n||cnt==0)continue;
					int a1,a2,a3;
					a1 = a2 = a3 = 0;
					if(i>=1)a1 = dp[i-1][j][k]+a[cnt][1];
					if(j>=1)a2 = dp[i][j-1][k]+a[cnt][2];
					if(k>=1)a3 = dp[i][j][k-1]+a[cnt][3];
	//				cout << a1 << '~' << a2 << '~' << a3 << '\n';
					dp[i][j][k] = mx3(a1,a2,a3);
	//				cout << i <<' ' << j << ' ' << k << "---" << dp[i][j][k] << '\n';
				}
			}
		}
		for(int i = 0; i <= n/2; i++)
		{
			for(int j = 0; j <= n/2; j++)
			{
//				cout << i << ' ' << j << ' ' << n-i-j << ' ' << dp[i][j][n-i-j] << '\n'; 
				ans = max(ans,dp[i][j][n-i-j]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
/*
4
4 2 1
2 3 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
/*
dp[i][t][k] = dp[i-1][t-1][k-1]+a[i][t],dp[i-1]x[k-1];
*/
