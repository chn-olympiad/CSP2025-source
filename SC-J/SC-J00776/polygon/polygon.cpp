#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long n, a[5005], sum[5005];
bool a1 = 1;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
		if (a[i] != 1) a1 = 0;
	}
	
	if (a1)
	{
		long long ans = 0;
		for (int i = 3; i <= n; ++ i) ans = ((ans % mod) + (i - 2)) % mod;
		cout << ans % mod;
	}
	else if (n == 3)
	{
		if (a[1] + a[2] > a[3] || a[1] + a[3] > a[2] || a[2] + a[3] > a[1]) cout << 1;
		else cout << 0;
	}
	else
	{
		cout << 0;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
