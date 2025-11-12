#include <bits/stdc++.h>
using namespace std;

int t,n,ans,dp[2][205][205][205];
struct node
{
	int x,y,z;
}a[100005];
void dfs(int x,int c1,int c2,int c3,int s)
{
	if (c1 > n/2 || c2 > n/2 || c3 > n/2) return;
	if (x > n)
	{
		ans = max(ans,s);
		return;
	}
	dfs(x+1,c1+1,c2,c3,s+a[x].x);
	dfs(x+1,c1,c2+1,c3,s+a[x].y);
	dfs(x+1,c1,c2,c3+1,s+a[x].z);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		memset(dp,0,sizeof dp);
		ans = 0;
		if (n <= 10) 
		{
			dfs(1,0,0,0,0);
			cout << ans << "\n";
			continue;
		}
		for (int i = 1;i <= n;i++)
		{
			for (int c1 = 0;c1 <= i;c1++)
			{
				for (int c2 = 0;c2 <= i;c2++)
				{
					int c3 = i-c1-c2;
					if (c3 < 0) continue;
					dp[i%2][c1][c2][c3] = 0;
					if (c1 != 0) dp[i%2][c1][c2][c3] = max(dp[(i-1)%2][c1-1][c2][c3]+a[i].x,dp[i%2][c1][c2][c3]);
					if (c2 != 0) dp[i%2][c1][c2][c3] = max(dp[(i-1)%2][c1][c2-1][c3]+a[i].y,dp[i%2][c1][c2][c3]);
					if (c3 != 0) dp[i%2][c1][c2][c3] = max(dp[(i-1)%2][c1][c2][c3-1]+a[i].z,dp[i%2][c1][c2][c3]);
				}
			}
		}
		for (int c1 = 0;c1 <= n/2;c1++)
		{
			for (int c2 = 0;c2 <= n/2;c2++)
			{
				int c3 = n-c1-c2;
				if (c3 > n/2) continue;
				ans = max(ans,dp[n%2][c1][c2][c3]);
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
