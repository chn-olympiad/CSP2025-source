#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int t;
int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i<s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			a[t] = int(s[i] -'0');
			t++;
		}
	}
	sort (a, a+t);
	for (int i = t-1; i>=0; i--) {
		cout << a[i];
	}
	return 0;
}
