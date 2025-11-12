#include <bits/stdc++.h>
using namespace std;
string s, t = "";
bool cmp(char a, char b) {
	return a > b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size(), len1 = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') t += s[i], len1++;
	}
	sort(t.begin(), t.end(), cmp); 
	for (int i = 0; i < len1; i++) {
		cout << t[i];
	}
	return 0;
}
