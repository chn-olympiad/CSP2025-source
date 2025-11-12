//dp[i][j]:第i名同学，选第j个社团可以获得的最大价值
#include <bits/stdc++.h>
#define int long
using namespace std;
const int N = 1e5 + 10;
int a[N][3];
struct node
{
	int x , clubs[3];
}dp[N][3];
int n;
signed main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			dp[i][0].x = 0;
			dp[i][1].x = 0;
			dp[i][2].x = 0;
			dp[i][0].clubs[0] = 0;
			dp[i][0].clubs[1] = 0;
			dp[i][0].clubs[2] = 0;
			dp[i][1].clubs[0] = 0;
			dp[i][1].clubs[1] = 0;
			dp[i][1].clubs[2] = 0;
			dp[i][2].clubs[0] = 0;
			dp[i][2].clubs[1] = 0;
			dp[i][2].clubs[2] = 0;
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		dp[1][0].x = a[1][0];
		dp[1][1].x = a[1][1];
		dp[1][2].x = a[1][2];
		dp[1][0].clubs[0] = 1;
		dp[1][1].clubs[1] = 1;
		dp[1][2].clubs[2] = 1;
		for(int i = 2;i <= n;i++)
		{
			if(dp[i - 1][0].clubs[0] < n / 2)
			{
				dp[i][0].x = max(dp[i][0].x , dp[i - 1][0].x + a[i][0]);
				if(dp[i - 1][0].clubs[1] < n / 2)
				{
					dp[i][1].x = max(dp[i][1].x , dp[i - 1][0].x + a[i][1]);
				}
				if(dp[i - 1][0].clubs[2] < n / 2)
				{
					dp[i][2].x = max(dp[i][2].x , dp[i - 1][0].x + a[i][2]);
				}
			}
			if(dp[i - 1][0].clubs[1] < n / 2)
			{
				if(dp[i - 1][0].clubs[0] < n / 2)
				{
					dp[i][0].x = max(dp[i][0].x , dp[i - 1][0].x + a[i][0]);
				}
				dp[i][1].x = max(dp[i][1].x , dp[i - 1][0].x + a[i][1]);
				if(dp[i - 1][0].clubs[2] < n / 2)
				{
					dp[i][2].x = max(dp[i][2].x , dp[i - 1][0].x + a[i][2]);
				}
			}
			if(dp[i - 1][0].clubs[2] < n / 2)
			{
				if(dp[i - 1][0].clubs[0] < n / 2)
				{
					dp[i][0].x = max(dp[i][0].x , dp[i - 1][0].x + a[i][0]);
				}
				if(dp[i - 1][0].clubs[1] < n / 2)
				{
					dp[i][1].x = max(dp[i][1].x , dp[i - 1][0].x + a[i][1]);
				}
				dp[i][2].x = max(dp[i][2].x , dp[i - 1][0].x + a[i][2]);
			}
			
			
			
			if(dp[i - 1][1].clubs[0] < n / 2)
			{
				dp[i][0].x = max(dp[i][0].x , dp[i - 1][1].x + a[i][0]);
				if(dp[i - 1][1].clubs[1] < n / 2)
				{
					dp[i][1].x = max(dp[i][1].x , dp[i - 1][1].x + a[i][1]);
				}
				if(dp[i - 1][2].clubs[2] < n / 2)
				{
					dp[i][2].x = max(dp[i][2].x , dp[i - 1][1].x + a[i][2]);
				}
			}
			if(dp[i - 1][1].clubs[1] < n / 2)
			{
				if(dp[i - 1][0].clubs[0] < n / 2)
				{
					dp[i][0].x = max(dp[i][0].x , dp[i - 1][1].x + a[i][0]);
				}
				dp[i][1].x = max(dp[i][1].x , dp[i - 1][1].x + a[i][1]);
				if(dp[i - 1][2].clubs[2] < n / 2)
				{
					dp[i][2].x = max(dp[i][2].x , dp[i - 1][1].x + a[i][2]);
				}
			}
			if(dp[i - 1][1].clubs[2] < n / 2)
			{
				if(dp[i - 1][0].clubs[0] < n / 2)
				{
					dp[i][0].x = max(dp[i][0].x , dp[i - 1][1].x + a[i][0]);
				}
				if(dp[i - 1][1].clubs[1] < n / 2)
				{
					dp[i][1].x = max(dp[i][1].x , dp[i - 1][1].x + a[i][1]);
				}
				dp[i][2].x = max(dp[i][2].x , dp[i - 1][1].x + a[i][2]);
			}
			
			
			
			if(dp[i - 1][2].clubs[0] < n / 2)
			{
				dp[i][0].x = max(dp[i][0].x , dp[i - 1][2].x + a[i][0]);
				if(dp[i - 1][1].clubs[1] < n / 2)
				{
					dp[i][1].x = max(dp[i][1].x , dp[i - 1][2].x + a[i][1]);
				}
				if(dp[i - 1][2].clubs[2] < n / 2)
				{
					dp[i][2].x = max(dp[i][2].x , dp[i - 1][2].x + a[i][2]);
				}
			}
			if(dp[i - 1][2].clubs[1] < n / 2)
			{
				if(dp[i - 1][0].clubs[0] < n / 2)
				{
					dp[i][0].x = max(dp[i][0].x , dp[i - 1][2].x + a[i][0]);
				}
				dp[i][1].x = max(dp[i][1].x , dp[i - 1][2].x + a[i][1]);
				if(dp[i - 1][2].clubs[2] < n / 2)
				{
					dp[i][2].x = max(dp[i][2].x , dp[i - 1][2].x + a[i][2]);
				}
			}
			if(dp[i - 1][2].clubs[2] < n / 2)
			{
				if(dp[i - 1][2].clubs[0] < n / 2)
				{
					dp[i][0].x = max(dp[i][0].x , dp[i - 1][2].x + a[i][0]);
				}
				if(dp[i - 1][1].clubs[2] < n / 2)
				{
					dp[i][2].x = max(dp[i][2].x , dp[i - 1][2].x + a[i][2]);
				}
				dp[i][2].x = max(dp[i][2].x , dp[i - 1][2].x + a[i][2]);
			}
			
			
			
			if(dp[i][0].x == dp[i - 1][0].x + a[i][0])
			{
				dp[i][0].clubs[0] = dp[i - 1][0].clubs[0] + 1;
				dp[i][0].clubs[1] = dp[i - 1][0].clubs[1];
				dp[i][0].clubs[2] = dp[i - 1][0].clubs[2];
			}
			if(dp[i][0].x == dp[i - 1][1].x + a[i][0])
			{
				dp[i][0].clubs[0] = dp[i - 1][1].clubs[0] + 1;
				dp[i][0].clubs[1] = dp[i - 1][1].clubs[1];
				dp[i][0].clubs[2] = dp[i - 1][1].clubs[2];
			}
			if(dp[i][0].x == dp[i - 1][2].x + a[i][0])
			{
				dp[i][0].clubs[0] = dp[i - 1][2].clubs[0] + 1;
				dp[i][0].clubs[1] = dp[i - 1][2].clubs[1];
				dp[i][0].clubs[2] = dp[i - 1][2].clubs[2];
			}
			
			
			
			if(dp[i][1].x == dp[i - 1][0].x + a[i][1])
			{
				dp[i][1].clubs[0] = dp[i - 1][0].clubs[0];
				dp[i][1].clubs[1] = dp[i - 1][0].clubs[1] + 1;
				dp[i][1].clubs[2] = dp[i - 1][0].clubs[2];
			}
			if(dp[i][1].x == dp[i - 1][1].x + a[i][1])
			{
				dp[i][1].clubs[0] = dp[i - 1][1].clubs[0];
				dp[i][1].clubs[1] = dp[i - 1][1].clubs[1] + 1;
				dp[i][1].clubs[2] = dp[i - 1][1].clubs[2];
			}
			if(dp[i][1].x == dp[i - 1][2].x + a[i][1])
			{
				dp[i][1].clubs[0] = dp[i - 1][2].clubs[0];
				dp[i][1].clubs[1] = dp[i - 1][2].clubs[1] + 1;
				dp[i][1].clubs[2] = dp[i - 1][2].clubs[2];
			}
			
			
			
			if(dp[i][2].x == dp[i - 1][0].x + a[i][2])
			{
				dp[i][2].clubs[0] = dp[i - 1][0].clubs[0];
				dp[i][2].clubs[1] = dp[i - 1][0].clubs[1];
				dp[i][2].clubs[2] = dp[i - 1][0].clubs[2] + 1;
			}
			if(dp[i][2].x == dp[i - 1][1].x + a[i][2])
			{
				dp[i][2].clubs[0] = dp[i - 1][1].clubs[0];
				dp[i][2].clubs[1] = dp[i - 1][1].clubs[1];
				dp[i][2].clubs[2] = dp[i - 1][1].clubs[2] + 1;
			}
			if(dp[i][2].x == dp[i - 1][2].x + a[i][2])
			{
				dp[i][2].clubs[0] = dp[i - 1][2].clubs[0];
				dp[i][2].clubs[1] = dp[i - 1][2].clubs[1];
				dp[i][2].clubs[2] = dp[i - 1][2].clubs[2] + 1;
			}/*
			cout << dp[i][0].x << " " << dp[i][1].x << " " << dp[i][2].x << endl;
			cout << dp[i][0].clubs[0] << " " << dp[i][0].clubs[1] << " " << dp[i][0].clubs[2] << endl;
			cout << dp[i][1].clubs[0] << " " << dp[i][1].clubs[1] << " " << dp[i][1].clubs[2] << endl;
			cout << dp[i][2].clubs[0] << " " << dp[i][2].clubs[1] << " " << dp[i][2].clubs[2] << endl;
			cout << endl;*/
		}
		cout << max(dp[n][0].x , max(dp[n][1].x , dp[n][2].x)) << endl;
	}
	return 0;
}
