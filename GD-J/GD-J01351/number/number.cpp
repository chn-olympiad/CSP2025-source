#include <bits/stdc++.h>
using namespace std;
#define N 1000010
string s;
int a[N], k = 0;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; ++ i) {
		if (isdigit(s[i])) {
			int num = s[i] - '0';
			a[++ k] = num;
		}
	}
	sort(a + 1, a + 1 + k);
	for (int i = k; i >= 1; -- i) {
		cout << a[i];
	}
	return 0;
}
