#include <bits/stdc++.h>
using namespace std;
string s;
int len, number[15];
int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	cin >> s;
	len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') number[s[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		long long j = 0;
		while (j + 20 <= number[i]) {
			printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i);
			j += 20;
		}
		while (j + 1 <= number[i]) {
			printf ("%d", i);
			j++;
		}
	}
	return 0;
}
