#include <cstdio>
#include <string>
#include <iostream>
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

const int N = 1e6 + 5;
std::string s;
int num[N], id;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	std::cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
		if ('0' <= s[i] && s[i] <= '9')
			num[++ id] = (s[i] ^ 48);

	std::sort(num + 1, num + id + 1, std::greater <int> ());
	for (int i = 1; i <= id; i++)
		putchar(num[i] | 48);
	putchar('\n');
    return 0;
}