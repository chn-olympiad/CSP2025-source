#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

const int N = 507;
const int mod = 998244353;

typedef long long ll;

int n, m, a[N];
ll ans;

using namespace std;

string s;

int main ()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout); 
	scanf ("%d %d", &n, &m);
	cin >> s;
	int k = 1;
	for (int i = 1; i <= n; i ++)
		scanf ("%d", &a[i]);
	sort (a + 1, a + n + 1);
	for (k = 1; k <= n; k ++)
		if (a[k] > k)
			break;
	k = n - k + 1;
	if (s.find ('0') == string :: npos)
	{
		for (int j = k; j <= k; j ++)
		{
			ll A = 1;
			for (int i = k - j + 1; i <= k; i ++)
			{
				A *= i;
				A %= mod;
			}
			ans += A;
			ans %= mod;
		}
		printf ("%lld", ans);
	}
}
