#include <cstdio>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MAXSZ = 1 << 20;
char ch, buf[MAXSZ], *p1, *p2;
#define ge() (p1 == p2 && (p2 = buf + fread(p1 = buf, 1, MAXSZ, stdin), p1 == p2) ? EOF : *p1++)
template <typename T_T>
inline void read(T_T &x) {
	x = 0;
	
	while (ch < '0' || '9' < ch) ch = ge();
	while ('0' <= ch && ch <= '9') {
		x = x * 10 + (ch ^ 48);
		ch = ge();
	}
}
template <typename T_T>
inline void write(T_T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	
	if (x > 9) write(x / 10);
	putchar(x % 10 | 48);
}

const int N = 1005;
int score[N], n, m, xm;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			read(score[(i - 1) * m + j]);
			if (i == j && i == 1) xm = score[1];
		}
	}
	
	std::sort(score + 1, score + n * m + 1, std::greater <int> ());
	int num = 0;
	for (int i = 1; i <= n * m; i++) {
		if (score[i] == xm) {
			num = i;
			break;
		}
	}
	
	int lie = (num + n - 1) / n, hang = num - (lie - 1) * n;
	if (!(lie & 1)) hang = n - hang + 1;
		
	write(lie), putchar(' '), write(hang), putchar('\n');
	return 0;
}