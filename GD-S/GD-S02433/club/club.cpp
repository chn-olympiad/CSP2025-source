#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, A[N][3], B[N];
map<int, map<int, int> > f[N];
pair<int, int> C[N];

void solve() {
	cin >> n;
	bool fg = 1;
	for (int i = 1; i <= n; i++) {
		cin >> A[i][0] >> A[i][1] >> A[i][2];
		B[i] = A[i][0];
		fg &= (A[i][1] == 0 && A[i][2] == 0);
	}
	if (fg) {
		sort(B + 1, B + n + 1, greater<int>());
		int ans = 0;
		for (int i = 1; i <= n/2; i++) {
			ans += B[i];
		}
		cout << ans << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		f[i].clear();
		for (int a = 0; a <= n/2; a++) {
			for (int b = 0; b <= n/2 && a+b <= i; b++) {
				int c = i-a-b;
				if (a >= 1) {
					f[i][a][b] = max(f[i][a][b], f[i-1][a-1][b] + A[i][0]);
				}
				if (b >= 1) {
					f[i][a][b] = max(f[i][a][b], f[i-1][a][b-1] + A[i][1]);
				}
				if (c >= 1) {
					f[i][a][b] = max(f[i][a][b], f[i-1][a][b] + A[i][2]);
				}
			}
		}
	}
	int ans = 0;
	for (int a = 0; a <= n/2; a++) {
		for (int b = 0; b <= n/2 && a+b <= n; b++) {
			int c = n-a-b;
			if (c <= n/2) {
				ans = max(ans, f[n][a][b]);
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
} 
