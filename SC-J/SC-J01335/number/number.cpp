#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
long long cnt[12];
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (long long i = 0; i < (int)s.size(); i++) {
		if ('0' <= s[i] && '9' >= s[i]) cnt[s[i] - '0']++;
	}
	for (long long i = 9; i >= 0; i--) {
		while (cnt[i]) {
			cout << i;
			cnt[i]--;
		}
	}
	return 0;
}