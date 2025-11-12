#include <bits/stdc++.h>
using namespace std;

map <string, string> m;
map <string, bool> can;
string a, b, y, w1, w2, l, r, x, z;
int n, q, ans;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		m[a] = b;
		m[b] = a;
		can[a] = can[b] = true;
	}
	for (int i = 1; i <= q; i++) {
		cin >> w1 >> w2;
		ans = 0;
		for (int k = 1; k <= w1.size(); k++) {
			for (int l = 0, r = l + k - 1; r < w1.size(); l++, r++) {
				x.clear(), y.clear(), z.clear();
				int t = 0;
				for (; t < l; t++) {
					x += w1[t];
				}
				for (; t <= r; t++) {
					y += w1[t];
				}
				for (; t < w1.size(); t++) {
					z += w1[t];
				}
			//	cout << x << y << z << endl;
				if (can[y]) {
			//		cout << y <<endl;
					x += m[y];
					x += z;
					if (x == w2) ans++;
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
