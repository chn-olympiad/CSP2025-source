#include <bits/stdc++.h>

using namespace std;

int t,n,a[100000][5],dp[50005][50005][50005];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(--t)
	{
		cin >> n;
		int ans = 0;
		for(int i = 1;i<=n;++i)
			cin >> a[i][1] >> a[i][2] >> a[i][3];

		for(int l = 1;l <= n;++l)
			for(int i = 1;i <= n/2;++i)
				for(int j = 1;j <= n/2;++j)
					for(int k = 1;k <= n/2;++k)
						dp[i][j][k] = max(max(dp[i-1][j][k]+a[l][1],dp[i][j-1][k]+a[l][2]),dp[i][j][k-1] + a[l][3]);


		for(int i = 1;i <= n/2;++i)
			for(int j = 0;i <= n/2 - i;++j)
				ans = max(ans,dp[i][j][n-i-j]);
		cout << ans << endl;

	}

	return 0;
}
