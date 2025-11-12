#include <iostream>
#include <string>
using namespace std;

int a[100005];
int n, m;
long long mod = 998244353;
long long ans = 1;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int flag = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i - 1] == '0')
		{
			flag = 1;
		}
	}
	if (m == n)
	{
		if (flag == 1)
		{
			cout << 0;
			return 0;
		}
		for (int i = 1; i <= n; i++)
		{
			ans *= i;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	if (flag == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			ans *= i;
			ans %= mod;
		}
		cout << ans;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
