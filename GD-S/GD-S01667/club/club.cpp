#include <bits/stdc++.h>
using namespace std;

template<class T>
bool chmax(T& a, const T& b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}

void solve() {
	int n;
	cin >> n;
	
	vector<array<int, 3>> a(n);
	array<int, 3> t; t.fill(0);
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < 3; j++) {
	    	cin >> a[i][j];
	    	if (a[i][j] == 0) t[j]++;
		}
	
	long long res = 0;
	if (n <= 10) {
		auto dfs = [&](auto&& self, int i, long long sum, array<int, 3> cnt) -> void {
			if (i == n) {
				chmax(res, sum);
				return;
			}
			
			for (int j = 0; j < 3; j++)
				if (cnt[j] < n / 2) {
					auto cc = cnt;
					cc[j]++;
					self(self, i + 1, sum + a[i][j], cc);
				}
		};
		dfs(dfs, 0, 0, {0, 0, 0});
	} else if (t[1] == n && t[2] == n) {
		vector<int> A(n);
		for (int i = 0; i < n; i++) A[i] = a[i][0];
		sort(A.begin(), A.end(), greater<int>());
		for (int i = 0; i < n / 2; i++) res += A[i];
	} else if (t[2] == n) {
		vector<int> id(n);
		iota(id.begin(), id.end(), 0);
		sort(id.begin(), id.end(), [&](int i, int j) {
			return a[i][0] - a[i][1] > a[j][0] - a[j][1];
		});
		
		for (int i = 0; i < n; i++) {
			if (i < n / 2) res += a[id[i]][0];
			else res += a[id[i]][1];
		}
	}
	cout << res << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
