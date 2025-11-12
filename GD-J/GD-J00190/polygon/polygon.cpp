#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5 , MAX = 5e3 + 4 , mod = 998244353;
int Mod (int x)
{
	if (x >= mod) return x - mod;
	return x;
}
int n , f[N] , a[N];
signed main ()
{
	freopen ("polygon.in" , "r" , stdin);
	freopen ("polygon.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0) , cout.tie (0);
	cin >> n;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	sort (a + 1 , a + n + 1);
	f[0] = 1;
	int ans = 0;
	for (int i = 1;i <= n;i ++)
	{
		for (int j = MAX;j > a[i];j --) ans = Mod (ans + f[j]);
		for (int j = MAX;j >= 0;j --)
		{
			int k = min (MAX , j + a[i]);
			f[k] = Mod (f[j] + f[k]);
		}
	}
	cout << ans;
	return 0;
}
