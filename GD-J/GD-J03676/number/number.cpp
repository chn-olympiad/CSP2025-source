#include <bits/stdc++.h>
using namespace std;
int times[10];
string str;
int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	for (char c : str) {
		if (isdigit(c)) {
			++times[c - '0'];
		}
	}
	for (int i = 9; i >= 0; --i) {
		while (times[i]--) {
			putchar('0' + i);
		}
	}
	return 0;
}
