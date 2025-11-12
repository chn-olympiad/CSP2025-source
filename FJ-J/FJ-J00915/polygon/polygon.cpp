#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long f;
int n, a[5005], maxx, sum, num;
void dfs(int i)
{
	if (i > n)
	{
		return;
	}
	if (sum + a[i] > 2 * max(maxx, a[i]))
	{
		sum += a[i];
		maxx = max(maxx, a[i]);
		int maxn = maxx;
		num++;
		if (num >= 3)
		{
			f++;
			f = f % MOD;
		}
		for (int j = i; j <= n; j++)
		{
			dfs(j);
			sum -= a[j];
			maxx = maxn;
		}
	}
}
int main()
{
	freopen("polygon.in", "r", stdin); 
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	sort(a + 1, a + n + 1);
	dfs(1);
	cout << f;
	return 0;
}
