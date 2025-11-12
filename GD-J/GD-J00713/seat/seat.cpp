#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
void read(int *x) {
	int f = 1, ch = getchar();
	*x = 0;
	while (!isdigit(ch)) {
		if (ch == 45) {
			f = -f;
		}
		ch = getchar();
	}
	do {
		*x = (*x << 1) + (*x << 3) + (ch ^ 48);
		ch = getchar();
	} while(isdigit(ch));
}
void write(int x) {
	if (x < 0) {
		putchar(45);
		if (x == -2147483648ll) {
			putchar(50);
			x += 2000000000;
		}
		x = -x;
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + 48);
}
int cmp(const void *a, const void *b) {
	return (*(int *) a) > (*(int *) b) ? -1 : 1;
}
int n, m, al, a[100001], rp, dr, x = 1, y;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	read(&n);
	read(&m);
	al = n * m;
	for (int i = 1; i <= al; ++i) {
		read(&a[i]);
	}
	rp = a[1];
	qsort(a + 1, al, sizeof(int), cmp);
	for (int i = 1; i <= al; ++i) {
		if (dr == 0) {
			++y;
		}
		else {
			--y;
		}
		if (y % (n + 1) == 0 || y == 0) {
			++x;
			if (dr == 1) {
				y = 1;
				dr = 0;
			}
			else {
				y = n;
				dr = 1;
			}
		}
		if (a[i] == rp) {
			write(x);
			putchar(32);
			write(y);
			break;
		}
	}
}
