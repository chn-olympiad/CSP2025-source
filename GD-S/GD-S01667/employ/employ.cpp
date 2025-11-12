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

constexpr int P = 998244353;
void solve() {
	int n, m;
	cin >> n >> m;
	string S;
	cin >> S;
	
	vector<int> c(n);
	int ones = 0;
	for (int i = 0; i < n; i++) cin >> c[i], ones += S[i] - '0';
	
	int ans = 0;
	if (n <= 10) {
		vector<int> id(n);
		iota(id.begin(), id.end(), 0);
		do {
			int cnt = 0, gave = 0;
			for (int i = 0; i < id.size(); i++) {
				if (gave >= c[id[i]] || S[i] == '0') {
					gave++;
					continue;
				}
				cnt++;
			}
			ans += (cnt >= m);
		} while (next_permutation(id.begin(), id.end()));
	}
	else {
		ans = 1;
		for (int i = 1; i <= n; i++) ans = 1LL * ans * i % P;
	}
	cout << ans << '\n';
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t = 1;
	while (t--) solve();
	return 0;
}
