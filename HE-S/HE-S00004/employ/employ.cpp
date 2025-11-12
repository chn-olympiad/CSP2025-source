#include <bits/stdc++.h>
using namespace std;
const int N = 501, mod = 998244353;
int n, m, ans, c[N];
string s;
int p[N];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	bool flag = true;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	iota(p + 1, p + n + 1, 1);
	do
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (c[p[i]] > i - cnt - 1 && s[i - 1] == '1')
				cnt++;
		ans += (cnt >= m);
	}
	while (next_permutation(p + 1, p + n + 1));
	cout << ans;
	return 0;
}
