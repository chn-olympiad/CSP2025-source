#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, t = "";
	cin >> s;
	for (char x : s) {
		if ('0' <= x && x <= '9') {
			t.push_back(x);
		}
	}
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	cout << t;
	return 0;
}