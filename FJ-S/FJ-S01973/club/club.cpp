#include <bits/stdc++.h>
//#define int long long

template<typename T> void read(T &x) {
	x = 0; char s = getchar();
	for (; !isdigit(s); ) s = getchar();
	for (; isdigit(s); s = getchar()) x = (x << 3) + (x << 1) + s - '0';
}

const int N = 1e5 + 7;

int a[N][3], lnk[N][3], cnt[3];
int T, n, ans;

struct Node {
	int Max, Min, id, _;
	bool operator < (const Node &rhs) const {
		if (a[id][Max] - a[id][_] != a[rhs.id][rhs.Max] - a[rhs.id][rhs._]) return a[id][Max] - a[id][_] < a[rhs.id][rhs.Max] - a[rhs.id][rhs._];
		return a[id][Min] - a[id][_] < a[rhs.id][rhs.Min] - a[rhs.id][rhs._];
	}
}; std::priority_queue<Node> Q;

int check() { return 2 * std::max({ cnt[0], cnt[1], cnt[2] }) <= n; }
int A(int x, int _) {
	if (!_) return a[x][1] > a[x][2] ? 1 : 2;
	else if (_ == 1) return a[x][0] > a[x][2] ? 0 : 2;
	else return a[x][0] > a[x][1] ? 0 : 1;
}
int I(int x, int _) {
	if (!_) return a[x][1] > a[x][2] ? 2 : 1;
	else if (_ == 1) return a[x][0] > a[x][2] ? 2 : 0;
	else return a[x][0] > a[x][1] ? 1 : 0;
}
void Solve(int _) {
	for (int i = 1; i <= cnt[_]; i ++) Q.push((Node){ A(lnk[i][_], _), I(lnk[i][_], _), lnk[i][_], _ });
	for (int i = 1; i <= cnt[_] - (n / 2); i ++) {
		Node P = Q.top(); Q.pop(); ans -= a[P.id][P._];
		if (cnt[P.Max] < n / 2) cnt[P.Max] ++, ans += a[P.id][P.Max];
		else cnt[P.Min] ++, ans += a[P.id][P.Min];
	}
}

void solve() {
	while (!Q.empty()) Q.pop();
	ans = cnt[0] = cnt[1] = cnt[2] = 0; read(n);
	for (int i = 1; i <= n; i ++) for (int _ = 0; _ < 3; _ ++) read(a[i][_]);
	for (int i = 1; i <= n; i ++) {
		int pos = 0; for (int _ = 1; _ < 3; _  ++) if (a[i][pos] < a[i][_]) pos = _;
		lnk[++ cnt[pos]][pos] = i, ans += a[i][pos];
	}
	if (check()) return printf("%d\n", ans), void();
	int M = 0; for (int _ = 1; _ < 3; _  ++) if (cnt[M] < cnt[_]) M = _;
	Solve(M); printf("%d\n", ans);
}

signed main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (read(T); T --; ) solve();
	
	return 0;
}
