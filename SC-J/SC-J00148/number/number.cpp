#include <iostream>
using namespace std;
int n, m;
int a[1000005];
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	s = " " + s;
	for (int i = 1; i <= n; ++i) {
		if (isdigit(s[i])) {
			++a[s[i] - '0'];
		}
	}
	int fl = 0;
	for (int i = 9; i >= 0; --i) {
		if (i == 0 && fl == 0) {
			fl = 1;
			continue;
		}
		while (a[i]) {
			if (i != 0) {
				fl = 2;
			}
			cout << i;
			--a[i];
		}
	}
	if (fl == 1) {
		cout << 0;
	}
	return 0;
}