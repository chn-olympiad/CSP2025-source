#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000010], x = 0;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if ('0' <= s[i] && s[i] <= '9') {
			++x;
			a[x] = s[i] - '0';
		}
	}
	sort(a + 1, a + x + 1);
	for (int i = x; i >= 1; --i) {
		cout << a[i];
	}
	return 0;
}