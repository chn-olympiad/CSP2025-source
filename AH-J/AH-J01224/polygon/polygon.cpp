#include <bits/stdc++.h>

using namespace std;
int a[5005];

int main()
{
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	bool f_1 = 0;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			f_1 = 1;
		}
	}
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	if (n == 3)
	{
		int sum = a[1] + a[2] + a[3];
		if (sum - max (max (a[1], a[2]), a[3]) > max (max (a[1], a[2]), a[3]))
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	if (!f_1)
	{
		long long sum = 0, s1 = 2, s2 = n * (n - 1);
		for (int i = 3;i <= n;i ++)
		{
			s1 *= i;
			s2 *= (n - i + 1);
			sum += s2 / s1;
			s2 /= s1;
			s1 = 1;
			sum %= 998244353;
		}
		cout << sum;
	}
	return 0;
}
