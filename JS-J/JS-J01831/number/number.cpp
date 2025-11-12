#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[15];
int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	string s; cin >> s;
	int size = s.size ();
	for (int i = 0; i <= size - 1; i++) {
		char c = s[i];
		if (c >= '0' && c <= '9') {
			int t = (int)(c - '0');
			a[t]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
