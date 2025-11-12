#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 505;
const int Md = 998244353;
string s;
int c[N], n, m;
ll fac[N];
int main() {
	FASTIO;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	fac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = (fac[i - 1] * i) % Md;
	}
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	if (n <= 10) {
		vector<int> tmp;
		for (int i = 1; i <= n; ++i) {
			tmp.push_back(i);
		}
		int ans = 0;
		do{
			int pre = 0, cnt = 0;
			for (int id = 0; id < tmp.size(); ++id) {
				int i = tmp[id];
				if (pre >= c[i]) {
					++pre;
					continue;
				}
				if (s[id + 1] == '0') {
					++pre;
					continue;
				}
				++cnt;
			}
			if (cnt >= m) {
				++ans;
			}
		}while (next_permutation(tmp.begin(), tmp.end()));
		cout << ans << '\n';
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '1') {
			++cnt;
		}
	}
	if (cnt == n) {
		cout << fac[n] << '\n';
		return 0;
	}
	return 0;
}
// 8pts
