#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = (1 << 20) + 10;

int sum[N], pre[N], id[M];
int f[N];

void solve()
{
	int n, K; scanf("%d%d", &n, &K);
	for (int i = 1, a; i <= n; i ++ )
	{
		scanf("%d", &a);
		sum[i] = (sum[i - 1] ^ a);
	}
	memset(id, -1, sizeof id); id[0] = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int mb = (K ^ sum[i]);
		pre[i] = id[mb], id[sum[i]] = i;
	}
	for (int i = 1; i <= n; i ++ )
	{
		f[i] = f[i - 1];
		if (pre[i] != -1) f[i] = max(f[i], f[pre[i]] + 1);
	}
	printf("%d\n", f[n]);
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int T = 1;
	while (T -- ) solve();
	return 0;
}
