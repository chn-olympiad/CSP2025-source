#include <bits/stdc++.h>
const int N = 1e6 + 10;
//#define int long long
using namespace std;
string s;
int a[N], m;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i ++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[++m] = s[i] - '0';
	}
	sort(a + 1, a + 1 + m);
	for (int i = m; i >= 1; i --)
			cout << a[i];
	return 0;
}