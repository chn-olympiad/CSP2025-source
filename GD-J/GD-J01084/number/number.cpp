#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
int n, a[N], idx;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s; cin >> s, n = s.size();
	for (int i = 0; i < n; i++) 
		if ('0' <= s[i] && s[i] <= '9') 
			a[++idx] = s[i] - '0';
	sort(a + 1, a + idx + 1, greater<int>());
	for (int i = 1; i <= idx; i++) cout << a[i];
	return 0;
}
