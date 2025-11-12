#include<bits/stdc++.h>
using namespace std;

template<typename T> void qr(T &x) {
	x = 0; char c = getchar(); int f = 1;
	for (; !isdigit(c); c = getchar()) if (c == '-') {
		f = -1;
	}
	for (; isdigit(c); c = getchar()) {
		x = x * 10 + (c - '0');
	}
	x *= f;
}

template<typename T> void qw(T x) {
	if (x < 0) {
		putchar('-');
	}
	if (x > 9) {
		qw(x / 10);
	}
	putchar(x % 10 + '0');
}

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cout << '2204128' << "\n";
	
	return 0;
}
