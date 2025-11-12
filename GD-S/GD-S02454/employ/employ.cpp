#include <cstdio>
#include <vector>
#include <algorithm>

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
constexpr int N = 505, MOD = 998244353;

char st[N];
int a[N], p[N];
vector<int> vc;


int bf(int n, int m) {
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	do {
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if ((st[i] & 1) && i - 1 - cnt < a[p[i]])
				++cnt;
		if (cnt >= m)
			++ans;
	} while(next_permutation(p + 1, p + 1 + n));
	return ans;
}

int sol0(int n, int m) {
	int p = 1, cnt = 0;
	LL ans = 1;
	for (int k : vc) {
		for (; p <= n && a[p] < k; ++p)
			++cnt;
		if (cnt <= 0)
			return 0;
		ans = ans * cnt % MOD;
		--cnt;
	}
	for (int i = n - vc.size(); i; --i)
		ans = ans * i % MOD;
	return ans;
}


int solve() {
	int n = read(), m = read(), cnt = 0;
	scanf("%s", st + 1);
	for (int i = 1; i <= n; ++i) {
		if (st[i] & 1)
			vc.emplace_back(i);
		a[i] = read();
		if (a[i])
			++cnt;
	}
	sort(a + 1, a + 1 + n);
	if (vc.size() < m || cnt < m)
		return 0;
	LL ans = 1;
	for (int i = 1; i <= n; ++i)
		ans = ans * i % MOD;
	if (n <= 10)
		return bf(n, m);
	if (m == 1)
		return (ans - sol0(n, m) + MOD) % MOD;
	if (vc.size() >= n)
		return ans;
	return 0;
}

void main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	for (int t = T ? read() : 1; t; --t)
		printf("%d\n", solve());
	fclose(stdin);
	fclose(stdout);
	return;
}
}

int main() {
	Main::main();
	return 0;
}
