#include <bits/stdc++.h>

const int N = 5e2 + 5;

int n, m, s[N], c[N], p[N];
int ans;
char ch;

int read() {
	int res = 0, i = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') i = -i;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * i;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) {
		ch = getchar();
		while (ch != '0' && ch != '1') ch = getchar();
		s[i] = ch - '0';
	}
	for (int i = 1; i <= n; ++i) c[i] = read();
	std::iota(p + 1, p + n + 1, 1);
	int cnt, tot;
	do {
		cnt = tot = 0;
		for (int i = 1; i <= n; ++i)
			if (cnt >= c[p[i]]) ++cnt;
			else if (!s[i]) ++cnt;
			else ++tot;
		ans += tot >= m;
	} while (std::next_permutation(p + 1, p + n + 1));
	write(ans), puts("");
	return 0; 
}
