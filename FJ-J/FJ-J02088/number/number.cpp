#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
long long num[15];
int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	scanf ("%s", s + 1);
	int len = strlen (s + 1);
	for (int i = 1; i <= len; i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num[s[i] - '0'] ++;
		}
	}
	for (int i = 9; i >= 0; i --) {
		for (int j = 1; j <= num[i]; j ++) {
			printf ("%d", i);
		}
	}
	cout << endl;
	return 0;
}
