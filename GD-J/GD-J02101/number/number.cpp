#include<bits/stdc++.h>
using namespace std;
const int N = 10;
string s;
int cnt[N];
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
		for (int j = 0; j < cnt[i]; j++) {
			cout << i;
		}
	}
	cout << "\n";
	
	return 0;
}
