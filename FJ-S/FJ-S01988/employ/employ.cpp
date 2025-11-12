#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 505;
long long n, m, c[MAXN], a[MAXN], ans, cnt;
bool s[MAXN], A, FO;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	FO = A = true;
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
		char ch;
		cin >> ch;
		s[i] = (ch != '1');
		if (s[i])
			A = false;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if (c[i] == 0)
			FO = false;
	}
	if (m == n && (!A || FO))
	{ 
		cout << 0;
		return 0;
	}
	if (A)
	{
		ans = 1;
		for (int i = 2; i <= n; i++)
			ans = (ans * i) % MOD;
		cout << ans % MOD;
		return 0;
	}
	do
	{
		cnt = 0; //fail
		for (int i = 1; i <= n; i++)
			if (c[a[i]] <= cnt || s[i])
				cnt++;
		if (n - cnt >= m)
			ans++;
	} while(next_permutation(a + 1, a + n + 1));
	cout << ans % MOD;
    return 0;
}

