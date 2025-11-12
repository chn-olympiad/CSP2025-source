#include <bits/stdc++.h>
using ll = long long;
using std::cin;
using std::cout;
using std::cerr;
using std::min;
using std::max;
using std::swap;
const int MAXN = 1e4 + 10;
int n, q;
char s1[MAXN][MAXN], s2[MAXN][MAXN];
char c1[MAXN], c2[MAXN];
bool Same() {
	int n1 = strlen(c1 + 1);
	for (int i = 1; i <= n1; ++i) {
		if(c1[i] != c2[i]) return false;
	}
	return true;
}
void Solve() {
	int n1 = strlen(c1 + 1);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int m1 = strlen(s1[i] + 1);
		for (int j = 1; j <= n1 - m1 + 1; ++j) {
			bool f = 1;
			for (int k = 1; k <= m1; ++k) {
				if(s1[i][k] != c1[j + k - 1]) {
					f = 0;
					break;
				}
			}
			if(!f) continue;
			for (int k = 1; k <= m1; ++k) {
				swap(s2[i][k], c1[j + k - 1]);
			}
			ans += Same();
			for (int k = 1; k <= m1; ++k) {
				swap(s2[i][k], c1[j + k - 1]);
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> (s1[i] + 1) >> (s2[i] + 1);
	}
	while(q--) {
		cin >> (c1 + 1) >> (c2 + 1);
		if(strlen(c1 + 1) != strlen(c2 + 1)) {
			cout << "0\n";
			continue;
		}
		Solve();
	}
	return 0;
}