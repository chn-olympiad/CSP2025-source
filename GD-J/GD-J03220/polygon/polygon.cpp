#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int n;
int a[5005];

int ans;

void dfs(int dep, int sum, int choose)
{
	if (n - dep + choose < 2) return ;
	if (dep > n)
	{
		return ;
	}
	if (sum > a[dep] && choose >= 2)
	{
		ans++;
		ans = ans % MOD;
//		cout << a[dep] << " " << sum << " " << choose << endl;
	}
	
	dfs(dep + 1, sum + a[dep], choose + 1);
	dfs(dep + 1, sum, choose);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
// 2 2 3 8 10

