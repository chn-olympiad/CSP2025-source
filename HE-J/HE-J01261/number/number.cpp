#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXNUM = 9 + 5;
int t[MAXNUM];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char tc = s[i];
		if ('0' <= tc && tc <= '9') {
			int ti = tc - '0';
			t[ti]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= t[i]; j++) {
			cout << i;
		}
	} 
	cout << endl;
	return 0;
}
