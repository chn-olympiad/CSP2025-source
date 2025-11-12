#include <cstdio>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;

namespace Main {

typedef long long LL;
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


constexpr int T = 0;
constexpr int N = 10005, M = 1000005, K = 11;

array<int, 3> e[M], e1[N];
pair<int, int> a[K][N];
int p[K];
pair<int, int> b[N];

struct Set {
	static constexpr int N = 10005;
	int f[N];

	void clear(int n) {
		for (int i = 0; i <= n; ++i)
			f[i] = i;
		return;
	}

	int find(int x) {
		return x == f[x] ? x : f[x] = find(f[x]);
	}

	int merge(int x, int y) {
//		printf("%d %d\n", x, y);
		x = find(x);
		y = find(y);
		return x == y ? x : f[y] = x;
	}

	bool query(int x, int y) {
//		printf("q %d %d\n", x, y);
		return find(x) == find(y);
	}

} st;

LL calc(int n, int m, int s) {
//	printf("#s %d\n", s);
	LL ans = 0, cnt = 0;
	priority_queue<pair<int, int>> q;
	q.emplace(-e1[p[m] = 1][0], m);
	for (int i = 0; i < m; ++i)
		if (s >> i & 1) {
			++cnt;
			ans += a[i][0].first;
			q.emplace(-a[i][p[i] = 1].first, i);
		}
	st.clear(n + m);
//	for (int i = 1; i < n + cnt;) {
	for (int i = 1; i < n + cnt && q.size();) {
		int x = q.top().second;
		q.pop();
		if (x == m) {
			if (!st.query(e1[p[m]][1], e1[p[m]][2])) {
				++i;
				st.merge(e1[p[m]][1], e1[p[m]][2]);
				ans += e1[p[m]][0];
			}
			if (++p[m] < n)
				q.emplace(-e1[p[m]][0], m);
			continue;
		}
		if (!st.query(n + x + 1, a[x][p[x]].second)) {
			++i;
			st.merge(n + x + 1, a[x][p[x]].second);
			ans += a[x][p[x]].first;
		}
		if (++p[x] <= n)
			q.emplace(-a[x][p[x]].first, x);
	}
	return ans;
}

void solve() {
	int n = read(), m = read(), k = read(), tot = 0;
	LL ans = 0;
	for (int i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		e[i] = array<int, 3>{w, u, v};
	}
	sort(e + 1, e + 1 + m);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j <= n; ++j)
			a[i][j] = make_pair(read(), j);
		sort(a[i] + 1, a[i] + 1 + n);
	}
	st.clear(n);
	for (int i = 1; i <= m; ++i)
		if (!st.query(e[i][1], e[i][2])) {
			st.merge(e[i][1], e[i][2]);
			e1[++tot] = e[i];
			ans += e[i][0];
		}
//	puts("fjdsl");
//	return;
	for (int i = 1; i < 1 << k; ++i)
		ans	= min(ans, calc(n, k, i));
	printf("%lld\n", ans);
	return;
}

void main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
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
