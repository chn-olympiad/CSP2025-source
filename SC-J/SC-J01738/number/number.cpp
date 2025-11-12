#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
long long a[15];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string str;
	cin >> str;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		char ch = str[i];
		if (ch >= '0' && ch <= '9') {
			int n = ch - '0';
			a[n]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (long long j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	cout << "\n";
	return 0;
}