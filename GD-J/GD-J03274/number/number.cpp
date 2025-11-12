#include <bits/stdc++.h>
using namespace std;


string s;
int top = 0;
int a[1000100];
int main() {
	freopen("number4.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (char ch : s) {
		if ('0' <= ch && ch <= '9') {
			a[++top] = ch - '0';
		}
	}
	sort(a + 1, a + top + 1);
	if (a[top] == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = top; i >= 1; i--) cout << a[i];
	return 0;
} 
