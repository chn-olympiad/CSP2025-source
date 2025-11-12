#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n = 0, q = 0;
string s[N][3];
int bm[5000010] = {};
string t[3];
int mov[N] = {};

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
		int ba = 0, bb = 0;
		for (int j = 0; j < s[i][1].size(); j++) {
			if (s[i][1][j] == 'b') {
				ba = j;
				break;
			}
		}
		for (int j = 0; j < s[i][2].size(); j++) {
			if (s[i][2][j] == 'b') {
				bb = j;
				break;
			}
		}
		mov[i] = ba - bb;
//		bm[ba - bb]++;
	}
	while(q--) {
		cin >> t[1] >> t[2];
		int ba = 0, bb = 0;
		for (int j = 0; j < t[1].size(); j++) {
			if (t[1][j] == 'b') {
				ba = j;
				break;
			}
		}
		for (int j = 0; j < t[2].size(); j++) {
			if (t[2][j] == 'b') {
				bb = j;
				break;
			}
		}
		int mo = ba - bb;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (mov[i] == mo && s[i][1].size() <= t[1].size()) {
				res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}
