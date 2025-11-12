#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using std::cin;
using std::cout;

int a[1000001];

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::string s;
	cin >> s;
	int k = 1;
	for (char i : s) {
		if (i >= '0' && i <= '9') {
			a[k++] = i - '0';
		}
	}
	k--;
	std::sort(a + 1, a + 1 + k, cmp);
	for (int i = 1; i <= k; i++) {
		cout << a[i];
	}
	return 0;
}