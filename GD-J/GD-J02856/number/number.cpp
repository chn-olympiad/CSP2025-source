#include <bits/stdc++.h>
#define fin for (int i = 1; i <= n; i++)
#define fjm for (int j = 1; j <= m; j++)
using namespace std;
int c[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	fin {
		if (isdigit(s[i])) {
			c[s[i]  - '0'] ++;
		}
	}
	for (int i = 9; i >= 0; i --) {
		for (int j = 1; j <= c[i]; j++) {
			cout << i;
		}
	}
	cout << endl;
	return 0;
}
