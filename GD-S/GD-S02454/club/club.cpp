#include <cstdio>
#include <algorithm>

using namespace std;

namespace Main {

typedef long long LL;

constexpr int T = 1;
constexpr int N = 100005;

LL read() {
	LL ch, res = 0, f = 0;
	for (ch = getchar(); (ch < '0' || ch > '9') && ch != '-'; ch = getchar());
	if (ch == '-') {
		f = 1;
		ch = getchar();
	}
	for (; '0' <= ch && ch <= '9'; ch = getchar())
		res = res * 10 + (ch & 15);
	return f ? -res : res;
}


int a[N][3], p[N][3];
pair<int, int> b[N];

void solve() {
	int n = read(), c[3] = {0, 0, 0};
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			a[i][j] = read();
			p[i][j] = j;
		}
		sort(p[i], p[i] + 3, [&](int x, int y){return a[i][x] < a[i][y];});
		b[i] = make_pair(a[i][p[i][2]] - a[i][p[i][1]], i);
	}
	sort(b + 1, b + 1 + n);
	for (int i = n; i; --i) {
		int x = b[i].second, t = c[p[x][2]] < n / 2 ? 2 : 1;
		++c[p[x][t]];
		ans += a[x][p[x][t]];
	}
	printf("%lld\n", ans);
	return;
}

void main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (int t = T ? read() : 1; t; --t)
		solve();
	fclose(stdin);
	fclose(stdout);
	return;
}
}

int main() {
	Main::main();
	return 0;
}
