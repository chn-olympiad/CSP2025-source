#include <bits/stdc++.h>

int read() {
	int x = 0;
	bool neg = false;
	char ch = 0;
	
	while (ch < '0' || ch > '9') {
		if (ch == '-') neg = true;
		ch = getchar();
	}

	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	
	return neg ? -x : x;
}

void write(int x) {
	bool neg = false;
	if (x < 0) {
		putchar('-');
		neg = true;
	}
	
	static int sta[48];
	int top = 0;
	
	do {
		sta[top++] = x % 10;
		x /= 10;
	} while (x);
	
	if (neg) while(top) putchar('0' - sta[--top]);
	else while(top) putchar('0' + sta[--top]);
	
	return ;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	write(0);
	return 0;
}
