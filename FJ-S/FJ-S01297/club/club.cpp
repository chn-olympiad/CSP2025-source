#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int cnt[5], ag[5][N];

void solve()
{
	int n; scanf("%d", &n);
	int res = 0;
	for (int i = 1; i <= 3; i ++ ) ag[i][0] = cnt[i] = 0;
	for (int i = 1, a, b, c; i <= n; i ++ )
	{
		scanf("%d%d%d", &a, &b, &c);
		int mx = max(max(a, b), c);
		if (a == mx) res += a, cnt[1] ++ , ag[1][ ++ ag[1][0]] = a - max(b, c);
		else if (b == mx) res += b, cnt[2] ++ , ag[2][ ++ ag[2][0]] = b - max(a, c);
		else res += c, cnt[3] ++ , ag[3][ ++ ag[3][0]] = c - max(a, b);
	}
	for (int k = 1; k <= 3; k ++ )
	{
		if (cnt[k] <= n / 2) continue;
		sort(ag[k] + 1, ag[k] + 1 + ag[k][0]);
		for (int i = n / 2 + 1; i <= cnt[k]; i ++ ) res -= ag[k][i - n / 2];
	}
	printf("%d\n", res);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T -- ) solve();
	return 0;
}
