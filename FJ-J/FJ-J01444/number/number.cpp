#include <iostream>
#include <cstdio>
using namespace std;
string s;
int l, t[130];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s; l = s.size();
	for (register int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			t[s[i]]++;
		}
	}
	for (register char i = '9'; i >= '0'; i--) {
		for (register int j = 1; j <= t[i]; j++) {
			printf("%c", i);
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
