#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	int len = s.size();
	int x = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++x] = s[i] - '0';
		}
	}
	sort (a + 1, a + x + 1);
	for (int i = x; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}