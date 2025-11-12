#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

int n, ans = 0, a[100010][5], b[100010];
void dfs(int step, int sum, int x, int y, int z)
{
	if(step > n)
	{
		ans = max(ans, sum);
		return;
	}
	if(x < n / 2) dfs(step + 1, sum + a[step][1], x + 1, y, z);
	if(y < n / 2) dfs(step + 1, sum + a[step][2], x, y + 1, z);
	if(z < n / 2) dfs(step + 1, sum + a[step][3], x, y, z + 1);
}
bool cmp(int x, int y) {return x > y;}
void solve()
{
	cin >> n;
	ans = 0;
	bool A = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 3; j++) cin >> a[i][j];
		if(a[i][2] || a[i][3]) A = 0;
	}
	if(A)
	{
		for(int i = 1; i <= n; i++) b[i] = a[i][1];
		sort(b + 1, b + n + 1, cmp);
		int res = 0;
		for(int i = 1; i <= n / 2; i++) res += b[i];
		cout << res << endl;
		return;
	}
	dfs(1, 0, 0, 0, 0);
	cout << ans << endl;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	while(T--) solve();
	
	fclose(stdin); fclose(stdout);
	return 0;
}
