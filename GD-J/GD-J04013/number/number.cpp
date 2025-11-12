#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, ans;
	cin >> s;
	for (char c : s) {
		if (c >= '0' && c <= '9') {
			++a[c - '0']; 
		}
	}
	for (int i = 9; i >= 0; --i) {
		while (a[i]-- > 0) {
			cout << i;
		}
	}
}
