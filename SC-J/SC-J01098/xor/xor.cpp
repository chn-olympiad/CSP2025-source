#include <cstdio>
#include <cstring>
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
template <typename T_T>
inline T_T max(T_T a, T_T b) {return a > b ? a : b;}

const int N = 5e5 + 5, M = (1 << 20) + 5;
int n, a[N], f[N], k, Max[N];
int s[N], val_id[M];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	read(n), read(k);
	memset(val_id, -1, sizeof val_id);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	
	val_id[0] = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = (s[i - 1] ^ a[i]);

		if (val_id[s[i] ^ k] == -1) f[i] = 0;
		else f[i] = Max[val_id[s[i] ^ k]] + 1;
				
		val_id[s[i]] = i;
		Max[i] = max(Max[i - 1], f[i]);
	}
	
	write(Max[n]), putchar('\n');
	fclose(stdin), fclose(stdout);
	return 0;
}