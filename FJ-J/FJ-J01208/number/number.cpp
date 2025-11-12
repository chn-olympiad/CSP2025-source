#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		a[i] = s[i];
	}
	sort(a, a+s.length());
	for (int i = s.length(); i >= 0; i--) {
		if (a[i] >= '0' && a[i] <= '9') {
			cout << char(a[i]);
		}
	}
	return 0;
}
