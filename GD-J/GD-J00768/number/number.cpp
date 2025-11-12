#include <bits/stdc++.h>
using namespace std;
string s;
int Num[1000010], l;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			Num[++l] = s[i] - '0';
		}
	}
	sort(Num + 1, Num + l + 1);
	for (int i = l; i >= 1; --i) {
		cout << Num[i];
	}
	return 0;
}
