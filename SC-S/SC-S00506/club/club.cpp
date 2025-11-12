#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5+5;
long long t, n, d[N][4], ans;

void solve(long long x, long long a, long long b, long long c, long long sum) {
	if (x == n + 1) {
		ans = max(ans, sum);
		return;
	}
	if (a < n / 2) solve(x + 1, a + 1, b, c, sum + d[x][1]);
	if (b < n / 2) solve(x + 1, a, b + 1, c, sum + d[x][2]);
	if (c < n / 2) solve(x + 1, a, b, c + 1, sum + d[x][3]);
}

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		bool fj = 0, fsr = 0;
		for (long long i = 1; i <= n; i++) {
			cin >> d[i][1] >> d[i][2] >> d[i][3];
			if (d[i][3] != 0) fj = fsr = 1;
			if (d[i][2] != 0) fsr = 1;
		}
		if (fsr == 0) {
			vector<long long> p;
			for (long long i = 1; i <= n; i++) p.push_back(d[i][1]);
			sort(p.begin(), p.end(), cmp);
			for (long long i = 0; i < n / 2; i++) ans += p[i];
			cout << ans << endl;
			continue;
		} else if (fj == 0) {
			for (int i = 1; i <= n; i++) {
				ans += max(d[i][1], d[i][2]);
			}
			cout << ans << endl;
			continue;
		}
		solve(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}