#include <bits/stdc++.h>
using namespace std;

int a[20];
string s;

bool is_number(char S_s) {
	if ('0' <= S_s && S_s <= '9') return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (is_number(s[i])) {
			a[(s[i] - '0')]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (a[i]) {
			cout << i;
			a[i]--;
		}
	}
	cout << endl;
	return 0;
}