#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int tong[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; ++i) {
		if ('0' <= s[i] && s[i] <= '9') {
			++tong[s[i] - '0'];
		}
	}
	
	bool fl = 0;
	for (int i = 9; i >= 0; --i) {
		if (tong[i] != 0) {
			if (i == 0 && !fl) {
				printf("0");
			} else {
				for (int j = 1; j <= tong[i]; ++j) {
					printf("%d", i);
				}
//				cout << tong[i] * char(i);
				fl = 1;
			}
		}
	}
	return 0;
}