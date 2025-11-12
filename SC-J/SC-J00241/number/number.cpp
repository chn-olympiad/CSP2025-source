#include <bits/stdc++.h>
using namespace std;

bool cmp(char x, char y) {
	return x > y;
}
int main() {
	ios::sync_with_stdio(false);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	string w = "";
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			w += s[i];
		}
	}
	sort(w.begin(), w.end(), cmp);
	cout << w;
	return 0;
}