#include <bits/stdc++.h>

using namespace std;

int a[500010], n, k, qzh[500010], ans, o;
map<int, vector<int>> b;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		qzh[i] = a[i] ^ qzh[i - 1];
	}
	b[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		int t = qzh[i] ^ k;
		if (b[t].size()) {
			if (b[t][b[t].size() - 1] >= o) {
				o = i;
				ans += 1;
			}
		}
		b[qzh[i]].push_back(i);
	}
	cout << ans << endl;
	
	return 0;
}
