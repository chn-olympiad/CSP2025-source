#include <bits/stdc++.h>
using namespace std;

string s;
int a[(int)1e6 + 5], n;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] <= '9' && s[i] >= '0')
			a[++n] = s[i] - '0';
	}
	sort(a + 1, a + 1 + n, [](int a, int b){ return a > b; });
	for (int i = 1; i <= n; ++i)
		cout << a[i];
	return 0;
}

