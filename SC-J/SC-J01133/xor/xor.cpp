#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, k;
int a[N], sum[N], dp[N][2];
map<int, int> mp;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] ^ a[i];
	}
	mp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		int j = 0, num = sum[i] ^ k;
		if (mp.count(num))
		{
			j = mp[num];
			dp[i][1] = max(dp[j][0], dp[j][1]) + 1;
		}
		mp[sum[i]] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, max(dp[i][0], dp[i][1]));
	printf("%d\n", ans);
	return 0;
}
