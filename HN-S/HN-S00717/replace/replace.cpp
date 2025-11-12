#include <cstdio>
#include <iostream>

struct stringPair {
	string s1, s2;
};

inline void read(int &goal) {
	int x = 0;
	char c = getchar();
	while (c > 57 || c < 48) c = getchar();
	while (c > 47 && c < 58) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	goal = x;
}
inline void write(int n) {
	char buffer[10], *pos = buffer;
	do *pos++ = n % 10 + 48; while (n /= 10);
	do putchar(*--pos); while (pos > buffer);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0);

	int n, q; read(n); read(q);
	
	return 0;
}
