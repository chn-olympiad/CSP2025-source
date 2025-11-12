#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
struct Gro {
	string a, b;
}g[N];
int n, q;
long long ans;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> g[i].a >> g[i].b;
	while (q--) {
		ans = 0;
		string a, b, c;
		cin >> a >> b;
		for (int i = 1; i <= n; i++) {
			if (a.size() != b.size()) break;
			int fa = a.find(g[i].a), fb = b.find(g[i].b);
			if (fa != -1 && fb != -1) {
				c = a;
				c.replace(fb, g[i].b.size(), g[i].b);
				if (c == b) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
