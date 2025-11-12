#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define LL long long
//#define int long long

using namespace std;

int read() {
	int k = 0, kk = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			kk = -1;
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		k = k * 10 + c - '0';
		c = getchar();
	}
	return k * kk;
}

void write(int x) {
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

signed main() {

	return 0;
}

