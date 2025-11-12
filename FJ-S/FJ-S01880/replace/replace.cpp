#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	string a[N][2];
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	
	while (q--) {
		string t0, t1;
		cin >> t0 >> t1;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int begin = 0; begin + a[i][0].size() <= t0.size(); begin++) {
				auto end = begin + a[i][0].size() - 1;
				bool flag = 1;
				for (int j = begin; j <= end; j++) {
					if (t0[j] != a[i][0][j - begin]) {
						flag = 0;
					}
				}
				if (!flag) continue;
				string t2 = t0;
				for (int j = begin; j <= end; j++) {
					t2[j] = a[i][1][j - begin];
				}
				if (t1 == t2) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
