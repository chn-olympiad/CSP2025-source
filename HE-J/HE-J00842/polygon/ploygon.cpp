#include <iostream>
#include <queue>
#define int long long
#define _ %998244353
using namespace std;
const int N = 5005;
int n, a[N], ans;
void e(int maxn, int sum, int s)
{
	if(s > n)
	{
		if(sum > maxn * 2)
			ans = (ans + 1)_;
		return;
	}
	e(max(maxn, a[s]), sum + a[s], s + 1);
	e(maxn, sum, s + 1);
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	e(0, 0, 1);
	cout << ans << "\n";
	return 0;
}
