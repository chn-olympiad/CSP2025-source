#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5000 + 5, MOD = 998244353;
int n, cnt = 0;
int a[N];

void dfs(int step, int sum, int maxn)
{
	if (step > n)
	{
		if (sum > 2 * maxn) cnt = (cnt + 1) % MOD;
		return;
	}
	dfs(step + 1, sum + a[step], max(maxn, a[step]));
	dfs(step + 1, sum, maxn);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	dfs(1, 0, 0);
	cout << cnt << endl;
	return 0;
}
