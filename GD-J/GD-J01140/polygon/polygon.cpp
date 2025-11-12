#include <iostream>
using namespace std;
int a[5005], ans, n;
void dfs(int x, int sum, int maxn)
{
	if (x > n)
	{
		if (sum > maxn * 2)
		{
			ans++;
		}
		return;
	}
	dfs(x + 1, sum + a[x], max(maxn, a[x]));
	dfs(x + 1, sum, maxn); 
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
