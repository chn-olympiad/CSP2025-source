#include <bits/stdc++.h>
#define IO(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)

using namespace std;

const int N = 1e4 + 7;
const int mod = 998244353;

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
void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) { write(x / 10); }
	putchar(x % 10 + '0');
}

int main() {
	//IO("");
	int n = random(1, mod);
	
	write(n);
	return 0;
}
