#include <bits/stdc++.h>
using namespace std;
long long nums[10];
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (char a : s) {
		if (a - '0' >= 0 && a - '0' <= 9) {
			nums[a - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (long long j = 0; j < nums[i]; j++) {
			printf("%d", i);
		}
	}
	return 0;
}
