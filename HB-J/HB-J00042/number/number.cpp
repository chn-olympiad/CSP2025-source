#include <bits/stdc++.h>
using namespace std;

string s;

bool cmp(char x, char y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	sort(s.begin(), s.end(), cmp);
	for (int i = 0; i < len; i++) {
		if (isdigit(s[i])) {
			s = s.substr(i);
			break;
		}
	}
	cout << s;
	return 0;
}
