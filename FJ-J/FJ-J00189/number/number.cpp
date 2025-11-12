#include <bits/stdc++.h>
using namespace std;
bool cmp(char a, char b) {
	return a * 1 > b * 1;
}
int main() {
	freopen("number.in", "r", stdin); freopen("number.out", "w", stdout); cin.tie(0); cout.tie(0);
	string s = "", a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if ('0' <= a[i] && a[i] <= '9') {
			s += a[i];
		}
	}
	sort(s.begin(), s.end(), cmp);
	cout << s;
	return 0;
}
