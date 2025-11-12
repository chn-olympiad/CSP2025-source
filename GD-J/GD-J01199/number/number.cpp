#include <bits/stdc++.h>
using namespace std;
string ans;
string s;
int f[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (char c: s) {
		if (c >= '0' && c <= '9') {
			f[c-'0']++;
		}
	}
	ans = "";
	for (int i = 9; i >= 0; i--) {
		while (f[i]--) {
			ans.push_back(i + '0');
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}