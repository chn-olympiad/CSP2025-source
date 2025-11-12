#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 505, mod = 998244353;

int n, m, c[N], a[N], sum;
string s;

void solve()
{
	for (int i = 1; i <= n; i ++ ) a[i] = i;
	do
	{
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; i ++ )
		{
			if (cnt >= c[a[i]])
			{
				cnt ++ ;
				continue;
			}
			if (s[i - 1] == '0') cnt ++ ;
			else res ++ ;
		}
		if (res >= m) sum = (sum + 1) % mod;
	}while (next_permutation(a + 1, a + n + 1));
	cout << sum << endl;	
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	bool flag = 1;
	for (int i = 0; i < s.size(); i ++ ) if (s[i] == '0') flag = 0;
	for (int i = 1; i <= n; i ++ ) scanf("%lld", &c[i]);
	if (n <= 10) solve();
	else if (flag)
	{
		int p = 0;
		for (int i = 1; i <= n; i ++ ) if (c[i]) p ++ ;
		if (p < m)
		{
			cout << 0 << endl;
			return 0;
		}
		sum = 1;
		for (int i = 1; i <= n; i ++ ) sum = sum * i % mod;
		cout << sum << endl;
	}
	return 0;
}


