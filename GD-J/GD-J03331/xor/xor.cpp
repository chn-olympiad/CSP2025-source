#include <bits/stdc++.h>
using namespace std;
int b[505][505];
bool vis[505];
int yihuo(int a, int b) {
	if (a == 0 || b == 0) {
		return max(a, b);
	}
	string s, t, u;
	while (a) {
		s += a % 2 + '0';
		a /= 2;
	}
	while (b) {
		t += b % 2 + '0';
		b /= 2;
	}
	int m = max(s.size(), t.size());
	for (int i = 0; i < m; i++) {
		int tmpa = s[i] - '0', tmpb = t[i] - '0';
		if (tmpa == tmpb) {
			u += '0';
		} else {
			u += '1';
		}
	}
	int ans = 0, wei = 1;
	for (int i = 0; i < u.size(); i++) {
		ans += wei * (u[i] - '0');
		wei *= 2;
	}
	return ans;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, a;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		b[i][i] = a;
		for (int j = 1; j <= i; j++) {
			b[i][j] = yihuo(b[i - 1][j], a);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (b[i][j] == k) {
				bool f = 0;
				int st = min(i, j), en = max(i, j);
				for (int i = st; i <= en; i++) {
					if (vis[i] == true) {
						f = 1;
						break;
					}
				}
				if (f) {
					break;
				}
				ans++;
				for (int i = st; i <= en; i++) {
					vis[i] = true;
				}
			} 
		}
	}
	cout << ans;
	return 0;
}
