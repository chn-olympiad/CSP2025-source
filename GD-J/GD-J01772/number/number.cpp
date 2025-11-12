#include <bits/stdc++.h>

using namespace std;

string s;
int ns[12];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	for (int i = 0; i <= 9; i++) {
		ns[i] = 0;  // why did I write this line
	}
	cin >> s;
	for (char c : s) {
		if (c >= '0' && c <= '9') {
			ns[c - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < ns[i]; j++) {
			cout << i;
		}
	}
	cout << endl;
	return 0;
}
