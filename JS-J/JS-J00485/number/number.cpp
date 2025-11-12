#include <bits/stdc++.h>
using namespace std;
int a[1000005], cnt;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (auto i : s) {
		if ('0' <= i && i <= '9') a[++cnt] = i - '0';
	}
	sort(a + 1, a + 1 + cnt);
	for (int i = cnt; i > 0; i--) cout << a[i];
	return 0;
}
