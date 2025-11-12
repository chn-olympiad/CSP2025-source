#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
char ans[MAXN];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int j = 1;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			ans[j] = s[i];
			j++;
		}
	}
//	cout << j << '\n';
	sort(ans + 1, ans + j + 1);
	for (int i = j; i >= 1; --i) {
		if (ans[i] != ' ') {
			cout << ans[i];
		}
		else {
			continue;
		}
		
	}
	return 0;
} 
