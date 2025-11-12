#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int MAXN = 5005, MOD = 998244353;
int a[MAXN], dp[MAXN][MAXN], pre[MAXN];
int n;
LL ans = 0;

void dfs(int now, int sum)
{
	if (sum > a[now] * 2) ans++;
	if (sum < a[now]) return ;
	
	for (int i = now + 1; i <= n; i++)
		dfs(i, sum + a[i]);
	
	return ;
}

//int find(int now, int sum) // now 后最后一个满足条件的数的下标 
//{
//	int l = now, r = n;
//	while (l <= r)
//	{
//		int mid = (l + r) >> 1;
//		if (sum > a[mid]) l = mid + 1;
//		else r = mid - 1;
//	}
//	
//	return r;
//}

//int calc(int x, int y)
//{
//	LL ans = 1;
//	for (int i = x; i > y; i--)
//		ans = (ans * i) % MOD;
//	return ans;
//}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

//	memset(dp, -0x3f, sizeof(dp));
	
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	
	stable_sort(a + 1, a + n + 1); 
	
//	for (int i = 1; i <= a[n]; i++)
//		pre[i] = pre[i - 1] + (a[i] != 0);

	if (n <= 29)
	{
		dfs(0, 0);
		cout << ans << endl;
	}
	else
	{
		for (int len = 2; len <= n; len++)
		{
			for (int l = 1; l + len - 1 <= n; l++)
			{
				int r = l + len - 1;
				for (int div = l; div <= r - 1; div++)
					dp[l][r] = max(dp[l][r], dp[l][div] + dp[div + 1][r] + (pre[r] - pre[l - 1]) * (pre[r] - pre[l - 1] - 1) / 2) % MOD;
			}
		}
		
		int ans = -INT_MAX;
		for (int l = 1; l <= n; l++)
			for (int r = 1; r <= n; r++)
				ans = max(ans, dp[l][r]);
		cout << ans << endl;
	} 

	return 0;
}

