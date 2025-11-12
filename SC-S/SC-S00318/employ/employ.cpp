#include <bits/stdc++.h>
using namespace std;

const long long M = 998244353;
long long n, m;
char a[100005];
long long b[100005];
long long ans = 0;
long long vis[100005];
long long ksm(long long y)
{
	long long p = 1;
	for (int i = y; i >= 1; i--)
		p = p * i, p = p % M;
	return p;
}
void dfs(long long i, long long s, long long t)
{
	if (s >= m)
	{
		ans = ans + ksm(n - i + 1), ans = ans % M;
		return;
	}
	if (i == n + 1 || n - t < m)
		return;
	for (long long j = 1; j <= n; j++)
		if (!vis[j])
		{
			vis[j] = 1;
			if (a[i] == '0')
				dfs(i + 1, s, t + 1);
			else
				if (t >= b[j])
					dfs(i + 1, s, t + 1);
				else
					dfs(i + 1, s + 1, t);
			vis[j] = 0;
		}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	long k = 0;
	for (long long i = 1; i <= n; i++)
		cin >> a[i], k += a[i] - '0';
	for (long long i = 1; i <= n; i++)
		cin >> b[i];
	if (k == n)
	{
		cout << ksm(n);
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans;
	
	return 0;
}