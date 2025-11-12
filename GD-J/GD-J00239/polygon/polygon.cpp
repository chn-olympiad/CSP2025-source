#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, a[5005], ans;
signed main ()
{
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	if (n == 3)
	{
		if (a[1] + a[2] > a[3])
			cout << 1;
		else cout << 0;
	}
	return 0;
}
//Can I sleep about 2 hours till the test ending?
//I can't fall sleep!!!
//114514
//114514
