#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5;
ll n, k, a[N + 5], b, ans, c;
int main ()
{
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	bool fon = 1, ftw = 1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] != 1)
			fon = 0;
		if (a[i] != 0 && a[i] != 1)
			ftw = 0;
		if (a[i] == 0)
			b++;
		if (a[i] == 1)
			c++;
	}
	if ((n <= 2 && k == 0 && fon) || (n <= 100 && k == 0 && fon))
	{
		cout << n / 2;
		return 0;
	}
	if (ftw && k == 0)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (i == 0) ans++;
			else if (i <= n - 1 && a[i + 1] == a[i])
			{
				ans++;
				i++;
			}
		}
		cout << ans;
		return 0;
	}
	if (ftw && k == 1)
	{
		cout << c;
		return 0;
	}
	return 0;
}