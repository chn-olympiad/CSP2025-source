#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

int n, m, k, value = 1e18, b[N], tot, s[N], a[N];

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;

	for(int i = 1; i <= n; ++ i) {
		b[i] = 1e18;
		s[i] = 1e18;
	}

	for(int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		b[u] = min(b[u], w);
		b[v] = min(b[v], w);
	}

	for(int i = 1; i <= k; ++ i) {
		int t, x, sum = 0, num = 0;
		cin >> t;

		for(int j = 1; j <= n; ++ j) {
			cin >> x;
			if(x < b[j]) {
				num += x;
				sum ++;
				s[j] = 1;
			}
		}

		if(sum > 0) {
			if(value > t + num) {
				for(int j = 1; j <= n; ++ j) {
					if(s[j] == 1) {
						s[j] = 0;
						a[j] = 1;
					}
				}
				value = t + num;
			}
		}
	}

	for(int i = 1; i <= n; ++ i) {
		if(a[i]) continue;
		value += b[i];
	}

	cout << value;
	return 0;
}/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
