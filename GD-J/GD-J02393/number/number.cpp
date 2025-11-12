#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define i128 __int128
#define PII pair<int, int>
#define PLL pair<ll, ll>
using namespace std;

constexpr ll inf = (1ll << 62);
constexpr int N = 2e5 + 10;

void solve() {
	string s;
	cin >> s;
	vector<int> v;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			v.push_back(s[i] - '0');
		}
	}
	sort(v.begin(), v.end(), [&](int a, int b) {
		return a > b;
	});
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
