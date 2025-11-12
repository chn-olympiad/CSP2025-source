#include<bits/stdc++.h>
using namespace std;
int a1[100005], a2[100005], a3[100005];
int dp[100005];
int ans = 0;
int n;
void dfs(int x, int num, int cnt1, int cnt2, int cnt3)
{
	if(x == n + 1)
	{
		ans = max(ans, num);
		 return ;
	}
	for(int i = 1; i <= 3; i++)
	{
		if(i == 1 && cnt1 + 1 <=n / 2) 
		{
			dfs(x + 1, num + a1[x], cnt1 + 1, cnt2, cnt3);
		}
		if(i == 2 && cnt2 + 1 <= n / 2)
		{
			dfs(x + 1, num + a2[x], cnt1, cnt2 + 1, cnt3);
		}
		if(i == 3 && cnt3 + 1 <= n / 2)
		{
			dfs(x + 1, num + a3[x], cnt1, cnt2, cnt3 + 1);
		}
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}   

