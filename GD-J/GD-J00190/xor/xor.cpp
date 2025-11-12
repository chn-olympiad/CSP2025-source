#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5 , M = 1 << 20;
int n , k , s[N] , f[N] , lst[M] , mx[N];
signed main ()
{
	freopen ("xor.in" , "r" , stdin);
	freopen ("xor.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0) , cout.tie (0);
	cin >> n >> k;
	for (int i = 1;i <= n;i ++) cin >> s[i] , s[i] ^= s[i - 1];
	for (int i = 1;i <= n;i ++)
	{
		int w = s[i] ^ k;
		int p = lst[w];
		if (!p)
		{
			if (w == 0) f[i] = 1;
			else f[i] = 0;
		}
		else f[i] = mx[p] + 1;
		lst[s[i]] = i;
		mx[i] = max (mx[i - 1] , f[i]);
	}
	cout << mx[n];
	return 0;
}
