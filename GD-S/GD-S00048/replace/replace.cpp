#include <bits/stdc++.h>
using namespace std;
map<string, string> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	string a, b;
	int n, q, cnt;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		m[a] = b;
	}
	while (q--) {
		cin >> a >> b;
		cnt = 0;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 1; j <= a.size() - i; j++)
				if (a.substr(0, i) + m[a.substr(i, j)] + a.substr(i + j) == b) cnt++;
		}
		cout << cnt << endl;
	} 
	return 0;
}
