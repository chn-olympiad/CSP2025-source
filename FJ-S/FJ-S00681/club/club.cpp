#include <bits/stdc++.h>

using namespace std;

int t, n, mx[3], cha[3][20010], e[100010][3], k, m;
long long ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		cin >> n;
		m = n >> 1;
		memset(cha, 0, sizeof(cha));
		mx[0] = mx[1] = mx[2] = ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> e[i][0] >> e[i][1] >> e[i][2];
			if (e[i][0] >= e[i][1] && e[i][0] >= e[i][2]) {
				mx[0]++;
				k = 0;
			} else if (e[i][1] >= e[i][0] && e[i][1] >= e[i][2]) {
				mx[1]++;
				k = 1;
			} else {
				mx[2]++;
				k = 2;
			}
			sort(e[i], e[i] + 3);
			cha[k][e[i][2] - e[i][1]]++;
			ans += e[i][2];
		}
		if (mx[0] > m) {
			for (int i = 0; i < 20010; i++) {
				ans -= min(cha[0][i], mx[0] - m) * i;
				mx[0] -= cha[0][i];
				if (mx[0] <= m) break;
			}
		} else if (mx[1] > m) {
			for (int i = 0; i < 20010; i++) {
				ans -= min(cha[1][i], mx[1] - m) * i;
				mx[1] -= cha[1][i];
				if (mx[1] <= m) break;
			}
		} else if (mx[2] > m) {
			for (int i = 0; i < 20010; i++) {
				ans -= min(cha[2][i], mx[2] - m) * i;
				mx[2] -= cha[2][i];
				if (mx[2] <= m) break;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
} 
