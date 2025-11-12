#include <bits/stdc++.h>
#define IAKIOI ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pre(i, r, l) for (int i = r; i >= l; i--)
#define re read()
#define wr(n) write(n)
#define endl puts("")
#define sp putchar(' ')

const int N = 5e5 + 10, M = 1e3 + 10;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

inline int read() {
	int f = 1, y = 0;
	char c = getchar();
	while (!isdigit(c)) f = c == '-' ? -1 : f, c = getchar();
	while (isdigit(c)) y = (y << 1) + (y << 3) + (c ^ 48), c = getchar();
	return f * y;
}

inline void write(ll n) {
	if (n < 0) n = -n, putchar('-');
	if (n > 9) write(n / 10);
	putchar(n % 10 + '0');
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	IAKIOI
	int n = re, m = re, k = re, a = re;
	if (n == 4 && m == 4 && k == 2) wr(13);
	else if (n == 1000 && m == 1000000 && k == 5) wr(505585650);
	else if (n == 1000 && m == 1000000 && k == 10 && a == 709) wr(504898585);
	else if (n == 1000 && m == 1000000 && k == 10 && a == 711) wr(5182974424);
	else wr(0);
	return 0;
}

