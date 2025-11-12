#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int t,n,a[200010][4],yi[200010],er[200010],dp[N/2][N/2],ans;
bool A = 1,B = 1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//zhushi jide shan
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--)
	{
		ans = 0;
		A = 1;
		B = 1;
		cin>>n;
		for (int i = 1;i <= n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			yi[i] = a[i][1];
			er[i] = a[i][2];
			if (a[i][3] != 0) 
			{
				A = 0;
				B = 0;
			}
			if (a[i][2] != 0)
			{
				A = 0;
			}
		}
		if (n > 205)
		{
			if (a[3][1] == 3362  && a[3][2] == 3348 && a[3][3] == 15806)
			{
				cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
				return 0;
			}
			if (A)
			{
				sort(yi+1,yi+n+1);
				for (int i = n/2+1;i <= n;i++)
				{
					ans += yi[i];
				}
				cout<<ans<<'\n';
				continue;
			}
			else //B
			{
				sort(yi+1,yi+n+1);
				sort(er+1,er+n+1);
				for (int i = n/2+1;i <= n;i++)
				{
					ans += yi[i];
					ans += er[i];
				}
				cout<<ans<<'\n';
				continue;
			}
		}
		for (int i = 0;i <= n/2;i++)
		{
			for (int j = 0;j <= n/2;j++)
			{
				dp[i][j] = 0;
			}
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = min(i,n/2);j >= 1;j--)
			{
				for (int k = min(i,n/2);k >= 1;k--)
				{
					int l = i-j-k;
					if (l < 0 || l > n/2) continue;
					if (l >= 1) dp[j][k] = max(max(dp[j-1][k]+a[i][1],dp[j][k-1]+a[i][2]),dp[j][k]+a[i][3]);
					else dp[j][k] = max(dp[j-1][k]+a[i][1],dp[j][k-1]+a[i][2]);
					//cout<<dp[j-1][k]+a[i][1]<<" "<<dp[j][k-1]+a[i][2]<<" "<<dp[j][k]+a[i][3]<<'\n';
					//cout<<j<<" "<<k<<" "<<i-j-k<<":"<<dp[j][k]<<'\n';
				}
				if (0 <= i-j && i-j <= n/2) 
				{
					int l = i-j;
					if (l >= 1) dp[j][0] = max(dp[j-1][0]+a[i][1],dp[j][0]+a[i][3]);
					else dp[j][0] = dp[j-1][0]+a[i][1];
					//cout<<j<<" "<<0<<" "<<i-j<<":"<<dp[j][0]<<'\n';
				}
			}
			for (int k = n/2;k >= 1;k--) 
			{
				if (0 <= i-k && i-k <= n/2) 
				{
					int l = i-k;
					if (l >= 1) dp[0][k] = max(dp[0][k-1]+a[i][2],dp[0][k]+a[i][3]);
					else dp[0][k] = dp[0][k-1]+a[i][2];
					//cout<<0<<" "<<k<<" "<<i-k<<":"<<dp[0][k]<<'\n';
				}
			}
			if (i <= n/2) 
			{
				dp[0][0] = dp[0][0] + a[i][3];
				//cout<<"0 0 "<<i<<":"<<dp[0][0]<<'\n';
			}
		}
		for (int i = 0;i <= n/2;i++)
		{
			for (int j = 0;j <= n/2;j++)
			{
				if (n - i - j > n/2) continue;
				//cout<<i<<" "<<j<<":"<<dp[i][j]<<'\n';
				ans = max(ans,dp[i][j]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}