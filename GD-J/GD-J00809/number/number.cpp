#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int a[N], len;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') a[++len] = s[i] - '0';
	}
	sort(a + 1, a + 1 + len, greater<int>());
	for (int i = 1; i <= len; i++) {
		cout << a[i];
	}
	return 0;
}
