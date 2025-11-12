#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, n;
int a[100010][4];
//int dp[100010][4];
bool cmp(int k, int l)
{
	return k > l;
}
int dfs(int num, int choose, int a1, int a2, int a3)
{
	//printf("num = %d, choose -> %d, %d,%d,%d\n", num, choose, a1, a2, a3);
	if(num == n)
		return a[n][choose];
	else
	{
		int mx = 0;
		if(a1 + 1 <= n/2)
		{
			mx = max(dfs(num + 1, 1, a1 + 1, a2, a3) + a[num][choose], mx);
			//printf("dfs(%d + 1, 1, %d , %d, %d) = %d\n", num + 1, 1, a1 + 1, a2, a3, dfs(num + 1, 1, a1 + 1, a2, a3) + a[num][choose]);
		}
		
		if(a2 + 1 <= n/2)
		{
			mx = max(dfs(num + 1, 2, a1, a2 + 1, a3) + a[num][choose], mx);
			//printf("dfs(%d + 1, 2, %d , %d, %d) = %d\n", num + 1, 1, a1, a2 + 1, a3, dfs(num + 1, 1, a1, a2 + 1, a3) + a[num][choose]);
		}
		if(a3 + 1 <= n/2)
		{
			mx = max(dfs(num + 1, 3, a1, a2, a3 + 1) + a[num][choose], mx);
			//printf("dfs(%d + 1, 3, %d , %d, %d) = %d\n", num + 1, 1, a1, a2, a3 + 1, dfs(num + 1, 1, a1, a2, a3 + 1) + a[num][choose]);
		}
		//cout << " ---> mx = " << mx << endl;
		return mx;
	}
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		memset(a, 0, sizeof(a));
		int b[100010];
		memset(b, 0, sizeof(b));
		cin >> n;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= 3; j ++)
			{
				cin >> a[i][j];
				b[i] = a[i][1];
			}
		
		
		bool flag = true;
		for(int i = 1; i <= n; i ++)
			if(a[i][2] != 0) flag = false;
		if(flag)
		{
			int ans = 0;
			sort(b + 1, b + n + 1, cmp);
			for(int j = 1; j <= n / 2; j ++)
				ans += b[j];
			cout << ans;
		}
		else
			cout << dfs(0, 1, 0, 0, 0) << endl;
	}
	return 0;
}
