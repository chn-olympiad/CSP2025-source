#include <iostream>
#define ull unsigned long long
#define P 131
using namespace std;

int n, q, len[200000];
ull sx[200000], sy[200000], prex[1000001], prey[1000001], powP[1000001];

ull query(int l, int r, ull* pre) {
	if (l > r) {
		return 0;
	}
	return pre[r] - pre[l - 1] * powP[r - l + 1];
}

void init() {
	powP[0] = 1;
	for (int i = 1; i <= 1000000; ++i) {
		powP[i] = powP[i - 1] * P;
	}
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s, len[i] = s.size();
		for (char c : s) {
			sx[i] = sx[i] * P + c;
		}
		cin >> s;
		for (char c : s) {
			sy[i] = sy[i] * P + c;
		}
	}
}

void calculate() {
	while (q--) {
		string x, y;
		cin >> x >> y;
		if (x.size() != y.size()) {
			puts("0");
			continue;
		}
		int ans = 0, l = x.size();
		x = ' ' + x, y = ' ' + y;
		for (int i = 1; i <= l; ++i) {
			prex[i] = prex[i - 1] * P + x[i];
			prey[i] = prey[i - 1] * P + y[i];
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= l; ++j) {
				if (j + len[i] - 1 > l) {
					break;
				}
				if (query(1, j - 1, prex) == query(1, j - 1, prey)
					and query(j + len[i], l, prex) == query(j + len[i], l, prey)
					and query(j, j + len[i] - 1, prex) == sx[i] and query(j, j + len[i] - 1, prey) == sy[i]) {
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}
}

void solve() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	init(), calculate();
}

int main() {
	solve();
	return 0;
}