#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define int long long
int n, a[10005], ans, sum[10005], jc[15], tem, cnt;
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf ("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    if (n == 1) cout << 0;
    else if (n == 2) cout << 0;
    else if (n == 3 && a[1] + a[2] > a[3]) cout << 1;
    else if (n == 3) cout << 0;
    else cout << 0;
   	return 0;
}
