#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 505; 

int n, m, ans, c[kMaxN], p[kMaxN], f[kMaxN];
string s;

void S(int x) {
	if (x > n) {
		int cnt = 0, l = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt >= c[p[i]]) {
				cnt++;
				continue;
			}
			if (s[i] == '0') cnt++;
			else l++;
		}
		ans += (l >= m);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			f[i] = 1, p[x] = i;
			S(x + 1);
			f[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s, s = ' ' + s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	S(1);
	cout << ans;
	return 0;
}

