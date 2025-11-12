#include <bits/stdc++.h>
using namespace std;

const long long M = 998244353;
long long n;
long long b[5005];
long long a[5005];
long long ans;
long long ksm(long long x, long long n)
{
	long long p = 1;
	while (n)
	{
		if (n % 2 == 1)
			p = p * x % M;
		x = x * x % M;
		n /= 2;
	}
	return p;
}
void dfs(long long i, long long t, long long s, long long mx)
{
	if (i == n + 2)
		return;
	if (s > 2 * mx && t == 1)
		ans++, ans = ans % M;
	dfs(i + 1, 1, s + b[i], max(mx, b[i]));
	dfs(i + 1, 0, s, mx);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long k = 0;
	cin >> n;
	for (long long i = 1; i <= n; i++)
		cin >> b[i], k += b[i];
	if (k == n)
	{
		ans -= 1 + n + n * (n - 1) / 2;
		ans += ksm(2, n);
		ans = ans % M;
		cout << ans;
		return 0;
	}
	sort(b + 1, b + n + 1);
	dfs(1, 0, 0, 0);
	cout << ans;
	
	return 0;
}