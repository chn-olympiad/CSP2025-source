#include <iostream>
using namespace std;
const int maxn = 20;
int w[maxn];
int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s; cin >> s; int len = s.size();
	for (int i = 0; i < len; i ++) {
		if (s[i] > '9' || s[i] < '0') continue;
		w[s[i] - '0'] ++;
	} int fag = 0;
	for (int i = 9; i >= 1; i --) {
		if (w[i] != 0) fag = 1;
		for (int k = 1; k <= w[i]; k ++)
			cout << i;
	}
	if (fag == 0) {
		if (w[0] >= 1) cout << 0;
	} else {
		for (int i = 1; i <= w[0]; i ++) {
			cout << 0;
		}
	}
	return 0;
}
