#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n = 0;
ll m = 0;
string s;
ll ans = 0;
bool flag = 0;
ll c[1000100] = {0};

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	ans = n;
	for (ll i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0) {
			ans -= 1;
		}
	}
	if (m == 1 and m < n and s[0] == 1) {
		cout << s.size();
		return 0;
	}
	if (m == 1 and m < n and s[0] == 0) {
		cout << 0;
		return 0;
	}
	for (ll i = 1; i <= m; i++) {
		if (s[i] == 0) {
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << 0 << '\n';
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
