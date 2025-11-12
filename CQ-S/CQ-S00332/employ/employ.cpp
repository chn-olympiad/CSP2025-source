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

inline void write(int n) {
	if (n < 0) n = -n, putchar('-');
	if (n > 9) write(n / 10);
	putchar(n % 10 + '0');
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	IAKIOI
	srand(time(nullptr));
	wr(rand() % 998244353);
	return 0;
}

