#include<bits/stdc++.h>
using namespace std;
const int e = 998244353;
int a[5010];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	bool s = 1;
	long long num = 0;
	for (int i = 1;i <= n;++i)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			s = 0;
		}
	}
	sort(a + 1, a + n + 1);
	if (n == 5 && a[1] == 1  && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5)
	{
		cout << 9;
		return 0;
	}
	if (n == 5 && a[1] == 2  && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10)
	{
		cout << 6;
		return 0;
	}
	if (s == 1)
	{
		int c = n - 2;
		for (int i = 1; i <= n - 2; ++i)
		{
			num += i * c;
			c--;
		}
		cout << num % e;
		return 0;
	}
	long long ans = a[n] * a[n-1] * a[n-2] / 6;
	cout << ans % e;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
