#include <bits/stdc++.h>
using namespace std;

const int N = 200000, M = 5001, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, mod = 998244353;

long long jj[N];

long long jie (long long x)
{
	if (x <= 1)
	{
		return 1;
	}
	if (jj[x])
	{
		return jj[x];
	}
	return jj[x] = jie (x - 1) * x;
}

long long C (long long m, long long n)
{
	return (jie (m) / jie (m - n - 1) / jie (n)) % mod;
}

signed main ()
{
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	long long scnt1 = 0;
	for (long long i = 0; i < s.size (); i++)
	{
		if (s[i] == '1')
		{
			scnt1++;
		}
	}
	long long ans1 = C (n, m) % mod;
	long long ans2 = C (scnt1, m) % mod;
	long long ans = (ans1 * ans2) % mod;
	cout << ans;
	return 0;
}

/*
3 2
101
1 1 2

2
*/
