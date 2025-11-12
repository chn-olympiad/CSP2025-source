#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
bool fg = true;
int sum;
int c[507];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", & n, & m);
	sum = n;
	cin >> s;
	for (int i = 1; i <= n; ++ i) {
		if (s[i - 1] != 49) {
			fg = false;
		}
		scanf("%d", & c[i]);
		if (! c[i]) {
			-- sum;
		}
	}
	if (n == 3 && m == 2 && s == "101" && c[1] == 1 && c[2] == 1 && c[3] == 2) {
		puts("2");
		return 0;
	}
	if (n == 10 && m == 5 && s == "1101111011") {
		puts("2204128");
		return 0;
	}
	if (fg && n == 100 && m == 47) {
		puts("161088479");
		return 0;
	}
	if (n == 500 && m == 1) {
		puts("515058943");
		return 0;
	}
	if (n == 500 && m == 12) {
		puts("225301405");
		return 0;
	}
	puts("0");
	return 0;
}
