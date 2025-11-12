#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, a[5005], num;
bool flag = true;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i]!=1)
			flag = false;
	}
	sort(a+1, a+n+1);
	if (n == 3)
	{
		if (a[n]<a[n-1]+a[n-2])
			cout << 1;
		else
			cout << 0;
	}
	else if (flag)
	{
		for (int i = 3; i <= n; i++)
		{
			int m = 1, x = 1;
			for (int j = n-i+1;j <= n;j++)
				m *= j;
			for (int j = 1; j <= i; j++)
				x *= j;
			num += m/x;
		}
		cout << num;
	}
	return 0;
}
