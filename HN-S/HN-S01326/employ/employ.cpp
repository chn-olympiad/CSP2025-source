#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 505, kM = 998244353;

int n, m, s[kMaxN], c[kMaxN], b[kMaxN], ans;
bool vis[kMaxN], flag = 1;

void S(int x) {
	if (x > n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt >= c[b[i]]) {
				cnt++;
				continue;
			}
			if (!s[i]) {
				cnt++;
			}
		}
		ans += (n - cnt >= m);
		ans %= kM;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			b[x] = i;
			S(x + 1);
			vis[i] = 0;
		}
	}
}

int A(int n) {
	int ans = 1;
	for (int i = n; i >= 1; i--) {
		ans = 1LL * ans * i % kM;
	}
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char x;
		cin >> x;
		s[i] = x - '0';
		if (!s[i]) {
			flag = 0;
		}
	}
	int s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		s += !c[i];
	}
	if (n <= 10) {
		S(1);
		cout << ans;
		return 0;
	}
	if (flag) {
		int ans = 0;
		for (int i = 0; i <= s; i++) {
			if (s - i > m) {
				continue;
			} 
			ans = (ans + 1LL * A(n - i) * A(i) % kM) % kM;
		}
		cout << ans;
		return 0;
	}
	return 0;
}

