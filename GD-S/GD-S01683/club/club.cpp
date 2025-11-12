#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int t, a[N], b[N], c[N], n, m, ans;
int dp[205][205][205];

void dfs(int k, int an, int bn, int cn, int cnt)
{
	ans = max(ans, cnt);
	if (k > n)return ;
	if (dp[an][bn][cn] > cnt)return ;
	dp[an][bn][cn] = cnt;
	
	if (an < m)dfs(k + 1, an + 1, bn, cn, cnt + a[k]);
	if (bn < m)dfs(k + 1, an, bn + 1, cn, cnt + b[k]);
	if (cn < m)dfs(k +1 , an, bn, cn + 1, cnt + c[k]);
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof(dp));
		ans = 0;
		cin >> n;
		m = (n >> 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}
