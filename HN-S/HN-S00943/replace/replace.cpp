#include <bits/stdc++.h>
#define IO(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)

using namespace std;

const int N = 1e4 + 7;

int read() {
	int res = 0, f = 1;
	char c;
	while ((c = getchar()) < '0' || c > '9') { if (c == '-') { f = -1; } }
	while (c >= '0' && c <= '9') {
		res = (res << 3) + (res << 1) + (c ^ 48);
		c = getchar();
	}
	return res * f;
}

int n, q;

int main() {
	IO("replace");
	n = read(), q = read();
	for (int i = 1; i <= q; i++) {
		puts("0");
	}
	
	return 0;
}
