#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
ll a[maxn][4];
vector<ll> b[4];

void coder() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j) {
				cin >> a[i][j];
			}
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				ans += a[i][1];
				b[1].push_back(a[i][1] - max(a[i][2], a[i][3]));
			} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				ans += a[i][2];
				b[2].push_back(a[i][2] - max(a[i][1], a[i][3]));
			} else {
				ans += a[i][3];
				b[3].push_back(a[i][3] - max(a[i][1], a[i][2]));
			}
		}
		int p = b[1].size();
		int q = b[2].size();
		int t = b[3].size();
		if (p > n / 2) {
			int m = p - (n / 2);
			sort(b[1].begin(), b[1].end());
			for (int i = 0; i < m; ++i) {
				ans -= b[1][i];
			}
		} else if (q > n / 2) {
			int m = q - (n / 2);
			sort(b[2].begin(), b[2].end());
			for (int i = 0; i < m; ++i) {
				ans -= b[2][i];
			}
		} else if (t > n / 2) {
			int m = t - (n / 2);
			sort(b[3].begin(), b[3].end());
			for (int i = 0; i < m; ++i) {
				ans -= b[3][i];
			}
		}
		cout << ans << '\n';
		b[1].clear();
		b[2].clear();
		b[3].clear();
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	coder();
	
	return 0; 
}
