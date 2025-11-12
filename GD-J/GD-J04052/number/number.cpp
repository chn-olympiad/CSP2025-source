#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string s;
int cnt[15];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (auto ch: s) {
		if (ch >= '0' && ch <= '9') {
			cnt[ch - '0']++;
		}
	}
	string ans = "";
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= cnt[i]; j++) ans += char(i + '0');
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
