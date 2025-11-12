#include <iostream>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

const int MOD = 998244353;
ull n, m, cnt1, c[505];
string s;

ull bin_search(ull l, ull r) {
	while(l <= r) {
		ull mid = (l + r) / 2;
		if (c[mid] > n - m) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}

ull solve(ull a) {
	ull ans = 1;
	while(a) {
		ans = (ans * a) % MOD;
		a--;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (char ch : s) if (ch == '1') cnt1++;
	for (int i = 1;i <= n;i++) cin >> c[i];
	sort(c + 1, c + 1 + n);
	ull pos = bin_search(1, n);
	if (cnt1 == n) cout << (solve(n)) % MOD << "\n";
	else if (m == 1) cout << (solve(n - pos + 1) * solve(pos - 1)) % MOD << "\n";
	return 0;
}
