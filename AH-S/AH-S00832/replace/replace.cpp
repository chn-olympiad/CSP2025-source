#include <bits/stdc++.h>
using namespace std;
struct Node {
	string a, b;
}arr[200005];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].a >> arr[i].b;
	}
	for (int i = 1; i <= 1; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		long long ans = 0;
		int x = t1.size();
		for (int i = -1; i < x - 1; i++) {
			for (int j = i + 2; j <= x; j++) {
				string a = (i + 1 == 0 ? "" : t1.substr (0, i + 1));
				string b = t1.substr (i + 1, j - i - 1);
				string c = (x - j == 0 ? "" : t1.substr (j, x - j));
				for (int k = 1; k <= n; k++) {
					if (arr[k].a == b) {
						if (a + arr[k].b + c == t2) {
							ans ++;
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
