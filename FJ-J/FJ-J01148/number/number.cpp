#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int cnt[20];
string s;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			cnt[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= cnt[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
