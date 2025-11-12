#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct IO {
	IO() { freopen("number.in", "r", stdin), freopen("number.out", "w", stdout); }
	~IO() { fclose(stdin), fclose(stdout); }
} io;
char s[1000005];
int t[10];
int n, m;
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		if (isdigit(s[i])) t[s[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < t[i]; j++) {
			putchar('0' + i);
		}
	}
	putchar('\n');
	return 0;
}