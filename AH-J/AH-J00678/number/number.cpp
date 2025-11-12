#include<iostream>
#include<cstring>
#define N 1000100
using namespace std;
inline int read() {
	int x = 0, f = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) f = c == '-';
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}
inline void write(int x, int ed = -1) {
    if (x < 0) { x = -x; putchar('-'); }
    int i = 0; static char buf[40];
    do { buf[i++] = x % 10; x /= 10; } while(x);
    while (i) putchar(buf[--i] + '0');
    if (~ed) putchar(ed);
}
char c[N]; int n, num[15];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", c); n = strlen(c);
	for (int i = 0; i < n; ++i) if (c[i] >= '0' && c[i] <= '9') num[c[i] - 48]++;
	for (int i = 9; i >= 0; --i) for (int j = 0; j < num[i]; ++j) write(i);
	printf("\n");
	return 0;
}
