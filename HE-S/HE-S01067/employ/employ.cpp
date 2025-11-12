#include <bits/stdc++.h>
using namespace std;
const int A = 5e2 + 10, mod = 998244353;
int f(int n)
{
	if (n == 0)
		return 1;
	return (n % mod) * f(n - 1) % mod;
}
int c[A], m, n, sum;
string s;
bool flag;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 0; i < n; i ++)
		if (s[i] == '0')
			flag = 1;
	for (int i = 1; i <= n; i ++)
	{
		cin >> c[i];
		if (c[i] == 0)
			flag = 1;
	}
	if (flag)
		cout << 0;
	else if (m == n)
		cout << f(n);
	else
		cout << 0;
	return 0;
}
