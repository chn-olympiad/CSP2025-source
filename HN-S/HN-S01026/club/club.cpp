#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n, t, a[N][10], f[N][10], st[N][10], b[N], c[N];
bool fx, ff, fff;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		fx = ff = fff = 0;
		memset(f, 0, sizeof(f));
		memset(st, 0, sizeof(st));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) cin >> a[i][j];
			if (a[i][1]) fx = 1;
			if (a[i][2]) ff = 1;
			if (a[i][3]) fff = 1;
		}
		if (!fx && !ff) {
			ll ss = 0;
			for (int i = 1; i <= n; i++) b[i] = a[i][3];
			sort(b + 1, b + n + 1);
			for (int i = n / 2 + 1; i <= n; i++) ss += b[i];
			cout << ss << "\n";
			continue;
		}
		if (!fx && !fff) {
			ll ss = 0;
			for (int i = 1; i <= n; i++) b[i] = a[i][2];
			sort(b + 1, b + n + 1);
			for (int i = n / 2 + 1; i <= n; i++) ss += b[i];
			cout << ss << "\n";
			continue;
		}
		if (!ff && !fff) {
			ll ss = 0;
			for (int i = 1; i <= n; i++) b[i] = a[i][1];
			sort(b + 1, b + n + 1);
			for (int i = n / 2 + 1; i <= n; i++) ss += b[i];
			cout << ss << "\n";
			continue;
		}
		if (!fx) {
			ll ss = 0;
			for (int i = 1; i <= n; i++) b[i] = a[i][2], c[i] = a[i][3];
			sort(b + 1, b + n + 1);
			sort(c + 1, c + n + 1);
			for (int i = n / 2 + 1; i <= n; i++) ss += b[i];
			for (int i = n / 2 + 1; i <= n; i++) ss += c[i];
			cout << ss << "\n";
			continue;
		}
		if (!ff) {
			ll ss = 0;
			for (int i = 1; i <= n; i++) b[i] = a[i][1], c[i] = a[i][3];
			sort(b + 1, b + n + 1);
			sort(c + 1, c + n + 1);
			for (int i = n / 2 + 1; i <= n; i++) ss += b[i];
			for (int i = n / 2 + 1; i <= n; i++) ss += c[i];
			cout << ss << "\n";
			continue;
		}
		if (!fff) {
			ll ss = 0;
			for (int i = 1; i <= n; i++) b[i] = a[i][2], c[i] = a[i][1];
			sort(b + 1, b + n + 1);
			sort(c + 1, c + n + 1);
			for (int i = n / 2 + 1; i <= n; i++) ss += b[i];
			for (int i = n / 2 + 1; i <= n; i++) ss += c[i];
			cout << ss << "\n";
			continue;
		}
		f[1][1] = a[1][1], f[1][2] = a[1][2], f[1][3] = a[1][3];
		st[1][1] = st[1][2] = st[1][3] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				int sum = 0, o = 0;
				for (int k = 1; k <= 3; k++) {
					if (j == k && st[i - 1][k] >= n / 2) continue;
					if (f[i - 1][k] >= sum) {
						sum = f[i - 1][k];
						o = k;
					}
				}
				f[i][j] = sum + a[i][j];
				st[i][j] = st[i - 1][j] + 1;
			}
		}
		cout << max(f[n][1], max(f[n][2], f[n][3])) << endl;
	}
	return 0;
}
