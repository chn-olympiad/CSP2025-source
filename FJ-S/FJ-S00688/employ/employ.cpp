#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	int n , m , c[520] , n1;
	string s;
	cin >> n >> m >> s;
	n1 = n;
	for (int i = 1 ; i <= n1 ; i++)
	{
		cin >> c[i];
		if (c[i] == 0)
		{
			n--;
		}
	}
	long long ans = 1;
	for (int i = 1 ; i <= n ; i++)
	{
		ans *= i;
		ans %= 998244353;
	}
	cout << ans << " " << n;
	return 0;
}
