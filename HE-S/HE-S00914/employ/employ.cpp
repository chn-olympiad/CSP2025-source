#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 5;
int c[MAXN];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 0; i <= n - 1; i++) {
		cin >> c[i];
	}
	int ans = 0;
	do {
		int nw = 0;
		for (int i = 0; i < s.size(); i++) {
			if (nw >= c[i]) {
				continue;
			}
			if (s[i] == '0') {
				nw++;
			}
		}
		if (n - nw == m) ans++;
	} while (next_permutation(s.begin(), s.end()));
	cout << ans << endl;
	return 0;
}
