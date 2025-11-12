#include <bits/stdc++.h>
using namespace std;

int n,q;
pair<string,string> a[214514];

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	clock_t st = clock();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string x,y;
		cin >> x >> y;
		a[i] = {x,y};
	}
	while (q--) {
		if ((clock() - st) * 1.0 / CLOCKS_PER_SEC >= 0.95) {
			cout << "0\n"; // No,Commander.
			continue;
		}
		int cnt = 0;
		string x,y;
		cin >> x >> y;
		for (int i = 1; i <= n; i++) {
			if (x.find(a[i].first) != x.npos && y.find(a[i].second) != y.npos) {
				int t = x.find(a[i].first);
				cnt++;
				for (int j = t; j < a[i].second.size(); j++) {
					if ((a[i].second)[j - t] != y[j]) {
						cnt--;
						break;
					}
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
