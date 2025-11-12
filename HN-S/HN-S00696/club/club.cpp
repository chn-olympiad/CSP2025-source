#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 5;

long long a[N][5], n;

vector<long long> v[5];

void solve() {
	cin >> n;
	for (long long i = 1; i <= 3; i++) {
		v[i].clear();
	}
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		long long o = 0, cnt = 0;
		for (long long j = 1; j <= 3; j++) {
			cin >> a[i][j];
			if (o <= a[i][j]) {
				cnt = o, o = a[i][j];
			} else if (cnt < a[i][j]) {
				cnt = a[i][j];
			} 
		}
		for (long long j = 1; j <= 3; j++) {
			if (o == a[i][j]) {
				v[j].push_back(cnt - o);
				break;
			}
		}
		ans += o;
	}
	long long m = n / 2;
	for (long long i = 1; i <= 3; i++) {
		if ((long long)v[i].size() > m) {
			sort(v[i].begin(), v[i].end());
			long long o = 0;
			long long dis = (long long)v[i].size() - m;
			for (long long j = (long long)v[i].size() - 1; j >= 0; j--) {
				o++;
				ans += v[i][j];
				if (o == dis) {
					break;
				}
			}
		}
	}
	cout << ans << "\n"; 
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long T;
	for (cin >> T; T--; solve()) {
	}
	return 0;
} 
