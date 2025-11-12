#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	int u[100005], v[100005], w[15];
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	int gz[15][10005];
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> gz[i][j];
		}
	}
	int fy = 0, num[100005] = {};
	if (k == 0) {
		for (int i = 0; i <= m; i++) {
			num[i] = u[i] + v[i];
			if (num[i] > w[i]) {
				fy += w[i];
			} else {
				fy += num[i];
			}
		}
		cout << fy << endl;
	} else {
		int minn = 0x3f3f3f;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j += 2) {
				if (minn >= min(gz[i][j], gz[i][j + 1])) {
					minn = min(gz[i][j], gz[i][j + 1]);
				}
				
			}
		}
		cout << minn << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
