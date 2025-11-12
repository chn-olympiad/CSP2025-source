#include <bits/stdc++.h>

using namespace std;
using ULL = unsigned long long;

const int kB = 787, kL = 5e6 + 5;
const ULL kb = 520131478917891;

int n, q;
ULL p[kL];
struct V {
	ULL x, y;
	int l1, l2;
};
unordered_map<ULL, vector<V>> m;

struct H {
	string s;
	vector<ULL> h;
	void I() {
		ULL x = 0;
		for (int i = 0; i < s.size(); i++) {
			x = x * kB + s[i];
			h.push_back(x);
		}
	}
	ULL C(int l, int r) {
		if (l > r) {
			return 0;
		}
		return h[r] - (l ? h[l - 1] : 0ULL) * p[r - l + 1];
	} 
};

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	p[0] = 1;
	for (int i = 1; i < kL; i++) {
		p[i] = p[i - 1] * kB;
	}
	cin >> n >> q;
	for (string x, y; n--;) {
		cin >> x >> y;
		int l = 0, r = x.size() - 1;
		for (; l <= r && x[l] == y[l]; l++);
		for (; l <= r && x[r] == y[r]; r--);
		H a, b;
		a.s = x, b.s = y;
		a.I(), b.I();
		if (x != y) {
			m[a.C(l, r) * kb + b.C(l, r)].push_back({a.C(0, l - 1), b.C(r + 1, x.size() - 1), l, (int) x.size() - r - 1});
		}
	}
	for (string x, y; q--;) {
		cin >> x >> y;
		int ans = 0, l = x.size(), r = -1;
		for (int i = 0; i < x.size(); i++) {
			if (x[i] != y[i]) {
				l = min(l, i), r = max(r, i);
			}
		}
		H a, b;
		a.s = x, b.s = y;
		a.I(), b.I();
		for (auto i : m[a.C(l, r) * kb + b.C(l, r)]) {
			if (l >= i.l1 && x.size() - r - 1 >= i.l2) {
				ans += a.C(l - i.l1, l - 1) == i.x && b.C(r + 1, r + i.l2) == i.y;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
