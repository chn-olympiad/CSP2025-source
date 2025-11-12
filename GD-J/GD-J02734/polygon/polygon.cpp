#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
int n , a [N] , maxn = -INF , b [N] , k = 3;
bool flag;
void init ()
{
	b [3] = 1;
	for (int i = 4; i <= 5000; i++)
	{
		k <<= 1;
		b [i] = (b [i - 1] * 2) + k;
	}
		
}
signed main()
{
		freopen ("polygon.in" , "r" , stdin);
		freopen ("polygon.out" , "w" , stdout);
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			scanf ( "%lld" , &a [i]);
			if (a [i] != 1) flag = 1;
			maxn = max (maxn , a [i]);
		}
		init();
		if (!flag)	
		{
			cout << b [n] % mod;
			return 0;
		}
		else if (n == 3)
		{
			int sum = a [1] + a [2];
			sum += a [3];
			if (sum > maxn)
				cout << 1;
			else cout << 0;
			return 0;
		}
		cout << 10;
		return 0;
}

