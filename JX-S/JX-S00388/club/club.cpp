#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[1 << 20];
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1 ++)
template <typename T> inline void read(T &u) {
	u = 0; bool fl = 0; char c = gc();
	while (!isdigit(c)) fl |= c == '-', c = gc();
	while (isdigit(c)) u = (u << 3) + (u << 1) + (c ^ 48), c = gc();
	if (fl) u = ~(u - 1);
}
template <typename T> inline void write(T u) {
	static int stk[40], top = 0; if (u < 0) putchar('-'), u = ~(u - 1);
	while (u) stk[++ top] = u % 10, u /= 10;
	if (!top) putchar('0');
	while (top) putchar(stk[top --] ^ 48);
	return putchar('\n'), void();
}
typedef long long ll;
#define eb emplace_back
#define mkpr make_pair
#define lowbit(i) (i & (-i))
const int N = 1e5 + 5;
int n, a[N][3];
int tmp[N];
int fl[N], cnt;
struct Node {
	int val, id, col;
	bool operator< (const Node &u) { return val < u.val;}
}w[N];
inline void solve() {
	read(n); cnt = 0; ll ans = 0;
	int ct[3] = { 0, 0, 0};
	for (int i = 1; i <= n; ++ i) {
		int mx = -1, pos = -1;
		for (int co = 0; co < 3; ++ co) {
			read(a[i][co]);
			if (a[i][co] > mx) mx = a[i][co], pos = co;
		}
		fl[i] = pos, ans += a[i][pos];
	}
	for (int i = 1; i <= n; ++ i) ct[fl[i]] ++;
	bool flag = 1; int id = -1, mx = -1;
	if (ct[0] > (n >> 1)) id = 0, mx = ct[0];
	if (ct[1] > (n >> 1)) id = 1, mx = ct[1];
	if (ct[2] > (n >> 1)) id = 2, mx = ct[2];
	cnt = 0;
	for (int i = 1; i <= n; ++ i) if (fl[i] == id) {
		for (int co = 0; co < 3; ++ co) if (co != id) w[++ cnt] = (Node) { a[i][id] - a[i][co], i, co};
	}
	sort(w + 1, w + cnt + 1);
	for (int i = 1; i <= cnt && (mx > (n >> 1)); ++ i) if (fl[w[i].id] == id) ans -= w[i].val, fl[w[i].id] = w[i].col, mx --;
	write(ans);
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; read(T);
	while (T --) solve();
}