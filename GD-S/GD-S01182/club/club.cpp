#include <bits/stdc++.h>
using namespace std; 
int T, n, a[100005][5], dp[205][205][205]; 
bool flag1; 
pair<int, int> b[100005]; 
bool cmp(pair<int, int> x, pair<int, int> y)
{
	return x.first > y.first; 
}
int main()
{
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 
	
	ios_base::sync_with_stdio(0); 
	cin.tie(0), cout.tie(0); 
	cin >> T; 
	while(T--)
	{
		cin >> n; 
		flag1 = false; 
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3; j++)
				cin >> a[i][j]; 
		for(int i = 1; i <= n; i++)
		{
			if(a[i][3] != 0)
			{
				flag1 = true; 
			}
		}
		if(!flag1)
		{
			int ans = 0; 
			for(int i = 1; i <= n; i++)
			{
				b[i] = make_pair(a[i][1] - a[i][2], i); 
			}
			sort(b + 1, b + n + 1, cmp); 
			for(int i = 1; i <= n / 2; i++)
			{
				ans += a[b[i].second][1]; 
			}
			if(n & 1)
			{
				ans += max(a[b[n / 2 + 1].second][1], a[b[n / 2 + 1].second][2]); 
			}
			for(int i = n; i * 2 - 1 > n; i--)
			{
				ans += a[b[i].second][2]; 
			}
			cout << ans << "\n"; 
		}
		else
		{
			for(int i = 0; i <= n; i++)
			{
				for(int j = 0; j <= n; j++)
				{
					for(int k = 0; k <= n; k++)
					{
						dp[i][j][k] = 0; 
					}
				}
			}
			int ans = 0; 
			for(int _ = 1; _ <= n; _++)
			{
				for(int i = n; i >= 0; i--)
				{
					for(int j = n; j >= 0; j--)
					{
						for(int k = n; k > 0; k--)
						{
							if(i != 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[_][1]); 
							}
							if(j != 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + a[_][2]); 
							}
							if(k != 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + a[_][3]); 
							}
							ans = max(ans, dp[i][j][k]); 
						}
					}
				}
			}
			cout << ans << "\n"; 
		}
	}
	return 0; 
}
// In here i am going to be AFO
// max:75+16+20+28=139 yes,AFO
// I have noting to say,but...
// AFO in 2025/11/1
