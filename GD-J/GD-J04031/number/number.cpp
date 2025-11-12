#include<bits/stdc++.h>
using namespace std;
int cnt[110];
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			cnt[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (cnt[i]) {
			printf("%d", i);
			cnt[i]--;
		}
	}
	return 0;
}
