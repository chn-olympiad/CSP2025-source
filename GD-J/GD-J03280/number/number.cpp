#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int b[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			b[s[i] - '0']++;
		}
	}
	bool flag = 0;
	for (int i = 9; i >= 0; i--) {
		if (b[i] && i != 0) flag = 1;
		if (i == 0 && !flag) {
			printf("0");
			return 0;
		}
		for (int j = 1; j <= b[i]; j++) printf("%d", i);
	}
	return 0;
}
