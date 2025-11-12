#include <bits/stdc++.h>

using namespace std;

const int N = 27;

long long n, a[N];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	long long ans = 0;
	for (int i = 0; i < (1 << n); ++i)
	{
		long long sum = 0, mx = 0;
		for (int j = 0; j < n; ++j)
			if (i >> j & 1)
			{
				sum += a[j + 1];
				mx = max(mx, a[j + 1]);
			}
		if (sum > 2 * mx)
			ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}
