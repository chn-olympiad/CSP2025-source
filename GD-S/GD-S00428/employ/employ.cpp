
#include <bits/stdc++.h>
using namespace std;

const int N = 510, mod = 998244353;
int p[N], sd[N], c[N];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, res = 0;
	string s;
	cin >> n >> m >> s;
	for (int i = 0; i < n; ++i) sd[i + 1] = s[i] == '1', p[i + 1] = i + 1;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	do {
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (!sd[i] || c[p[i]] <= cnt) ++cnt;
			if (n - cnt < m) break;
		}
		if (n - cnt >= m) res = (res + 1) % mod;
	} while (next_permutation(p + 1, p + n + 1));
	cout << res << endl;
	return 0;
}

