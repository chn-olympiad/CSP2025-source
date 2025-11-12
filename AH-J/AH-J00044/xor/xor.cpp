#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 1;
int tmp[N];
int a[500001], p[500001], dp[500001], ans, q[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), p[i] = p[i - 1] ^ a[i];
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = q[i - 1];
		dp[i] = max(tmp[p[i] ^ k], dp[i]);
		tmp[p[i]] = max(tmp[p[i]], dp[i] + 1);
		q[i] = max(q[i - 1], dp[i]);
	}
	printf("%d", *max_element(dp + 1, dp + n + 1));
	return 0;
}
