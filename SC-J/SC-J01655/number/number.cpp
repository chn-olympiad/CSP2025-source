#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	char c;
	cin >> s;
	string a;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a += s[i];
		}
	}
	for (int i = 0; i < a.size(); i++) {
		for (int j = 1; j < a.size() - 1 - i; j++) {
			if (a[i] < a[i + j]) {
				int x;
				x = a[i];
				a[i] = a[i + j];
				a[i + j] = x;
			}
		}
	}
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	return 0;
}