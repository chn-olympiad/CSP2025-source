#include <bits/stdc++.h>
using namespace std;
const int N = 100020;
long long n, m, s[N], c[N], ans, cnt1, cnt;
string s1;
int main ()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s1;
	for (int i = 1; i <= n; i ++) cin >> c[i];
	for (int i = 0; i <= (int)s1.length(); i ++) {
		s[i + 1] = s1[i] - '0';
		if (s[i + 1] == 1 && s[i + 2] != 0) cnt1 ++;
		if (s[i + 1] == 0) cnt = cnt1;
	}
	if (n == m)
	{
		if (cnt == 0) cout << 1;
		else cout << 0;
		return 0;
	}
	else
	{
		if (m > cnt) {
			cout << 0;
			return 0;
		}
		int sum = 1;
		for (int i = 1; i <= cnt; i ++)
		{
			sum *= i;
			ans += sum;
			ans %= 998244353;
		}
		cout << ans;
		return 0;
	}
	return 0;
}
