#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const long long MOD = 998244353;

int n, m, p[N], c[N], specialflagA = 1, cnt, k;
long long ans;
char s[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		if (s[i] == '0')	specialflagA = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		p[i] = i;
		if (c[i] == 0)	cnt++;
	}
	
	if (n == m && !specialflagA) {
		cout << "0\n";
		return 0;
	}
	if (specialflagA && n - cnt < m) {
		cout << "0\n";
		return 0;
	}
	do {
		cnt = 0, k = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0')	cnt++;
			else if (cnt >= c[p[i]])	cnt++;
			else	k++;
		}
		if (k >= m)	ans++;
		ans %= MOD;
	} while (next_permutation(p + 1, p + n + 1));
	
	cout << ans << "\n";
	
	return 0;
}
