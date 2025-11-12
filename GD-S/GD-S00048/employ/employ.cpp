#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
struct peo {
	int n, ind;
	bool operator < (const peo& other) const {
		return ind < other.ind;
	}
} a[505];
bool ok[505];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, cntok, cntnok, ans = 0;
	char c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		ok[i] = (int) (c - '0');
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].n;
		a[i].ind = i;
	}
	do {
		cntok = cntnok = 0;
		for (int i = 1; i <= n; i++) {
			if (cntnok >= a[i].n) cntnok++;
			else if (!ok[i]) cntnok++;
			else cntok++;
		}
		if (cntok >= m) {
			ans++;
			ans %= mod;
		}
	} while (next_permutation(a + 1, a + n + 1));
	cout << ans;
	return 0;
}
