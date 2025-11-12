#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100010;

int n;
ll a[210][5], f[210][110][110];

ll dp() {
    memset(f, -0x3f, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, n / 2); j++) {
            for (int k = 0; k <= min(i, n / 2) && j + k <= i; k++) {
                int c = i - j - k;
                if (c < 0 || c > n / 2) continue;
                if (j > 0) {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i][1]);
                }
                if (k > 0) {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][2]);
                }
                if (c > 0 && c <= n / 2) {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][3]);
                }
            }
        }
    }
    ll res = 0;
    for (int i = 0; i <= n / 2; i++) {
        for (int j = 0; j <= n / 2; j++) {
            int k = n - i - j;
            if (k < 0 || k > n / 2) continue;
            res = max(res, f[n][i][j]);
        }
    }
    return res;
}

void solve() {
	cin >> n;
	bool A = true, B = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if (a[i][2] != 0 || a[i][3] != 0) A = false;
		if (a[i][3] != 0) B = false;
	}
	if (n <= 200) {
		cout << dp() << "\n";
	} else {
	    if (A) {
            vector<int> q;
            for (int i = 1; i <= n; i++) q.push_back(a[i][1]);
            sort(q.begin(), q.end());
            int s = 0;
            ll ans = 0;
            for (int i = q.size() - 1; i >= 0; i--) {
                ans += q[i];
                s++;
                if (s == n / 2) break;
            }
            cout << ans << "\n";
	    }
	    /*else if (B) {
            memset(g, -0x3f, sizeof(g));
            g[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= min(i, n / 2); j++) {
                    if (j > 0) {
                        g[i][j] = max(g[i][j], g[i - 1][j - 1] + a[i][1]);
                    }
                    if (i - j > 0) {
                        g[i][j] = max(g[i][j], g[i - 1][j] + a[i][2]);
                    }
                }
            }
            cout << g[n][n / 2] << "\n";
	    }*/
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
