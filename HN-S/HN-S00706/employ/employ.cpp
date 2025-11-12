// lichenxi108.rp = inf;
#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, m, a[N], id[N];
char c[N];

void solve0() {
	for (int i = 1; i <= n; i++) {
		id[i] = i;
	}
	int ans = 0;
	do {
		int cnt = 0, p = 0;
		for (int i = 1; i <= n; i++) {
			if (a[id[i]] <= p) {
				++p;
				continue;
			}
			if (c[i] == '1') cnt++;
			else p++;
		}
		if (cnt >= m) ans = (ans + 1) % 998244353;
	} while (next_permutation(id + 1, id + n + 1));
	cout << ans;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	bool f = 1;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == '0') f = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 10) {
		solve0();
		return 0;
	}
	if (f) {
		long long ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = ans * i % 998244353;
		}
		cout << ans;
		return 0;
	}
	
	return 0;
} 
