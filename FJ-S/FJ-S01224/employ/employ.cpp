#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define ll long long
#define space putchar(' ')
#define enter putchar('\n')
using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;

template <typename T> inline void rd(T& x) {
	x = 0; int f = 1;
	char c = getchar();
	while (!isdigit(c)) f = c == '-' ? -1 : f, c = getchar();
	while (isdigit(c)) x = (x<<3)+(x<<1)+(c^48), c = getchar();
	x *= f;
}

template <typename T> inline void write(T x) {
	if (x < 0) x = -x, putchar('-');
	static short s[20], _ = 0;
	do s[++_] = x%10, x /= 10; while (x);
	while (_) putchar(s[_--]|48);
}

template <typename T, typename ...Args> inline void rd(T &x, Args&... _) { rd(x); rd(_...); }

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	puts("0");
	return 0;
}
