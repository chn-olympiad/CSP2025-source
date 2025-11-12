#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
int c[505];
int p[505];
int q[505];

bool check() {
	for (int i = 1, cnt = 0; i <= n; i++)
		if (i - cnt - 1 < q[i] && s[i - 1] == '1' && ++cnt >= m)
			return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	if (n > 10) {
		cout << 0 << '\n';
		return 0;
	}
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> c[i], p[i] = i;
	int res = 0;
	do {
		for (int i = 1; i <= n; i++)
			q[i] = c[p[i]];
		if (check())
			res++;
	} while (next_permutation(p + 1, p + n + 1));
	cout << res << '\n';
	return 0;
}
