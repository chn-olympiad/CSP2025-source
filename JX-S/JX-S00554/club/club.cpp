#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int t, n;
int a1[N], a2[N], a3[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 2) {
			int a[3][4];
			for (int i = 1; i <= n; i++) {
				cin >> a[i][1] >> a[i][2] >> a[i][3];
			}
			int nmax = 0;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (i == j)	continue;
					nmax = max(nmax, a[1][i] + a[2][j]);
				}
			}
			cout << nmax << '\n';
			continue;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		sort(a1 + 1, a1 + n + 1, greater<int>());
		int ans = 0;
		for (int i = 1; i <= n / 2; i++) {
			ans += a1[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
