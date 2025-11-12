#include <bits/stdc++.h>
#define sp " "
#define el "\n"
#define r0 return 0
#define F(i, a, b, c) for (int i = a; i <= b; i += c)
#define fi first
#define se second
#define p 998244353
#define int long long

using namespace std;

typedef long long ll;
typedef string str;

int n, m;
str s;
int f[510];
std::bitset<510> v;
struct Info {
	int c, id;
} c[510];
int ans = 0;

inline void dfs(int x) {
	if (x == n + 1) {
		int cnt = 0, tot = 0;
		F(i, 1, n, 1) {
			if (cnt >= c[f[i]].c) {
				cnt++;
				continue;
			}
			(s[i] == '1' ? tot : cnt)++;
			if (tot == m) {
				break;
			}
		}
		if (tot >= m) {
			ans++;
		}
		return;
	}
	F(i, 1, n, 1) {
		if (!v[i]) {
			v[i] = 1;
			f[x] = i;
			dfs(x + 1);
			v[i] = 0;
		}
	}
}

signed main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = sp + s;
	int cntc = 0;
	F(i, 1, n, 1) {
		cin >> c[i].c;
		if (!c[i].c) {
			cntc++;
		}
		c[i].id = i;
	}
	if (n - cntc < m) {
		cout << 0 << el;
		r0;
	}
	//std::sort(c + 1, c + n + 1);
	bool is1 = 1;
	F(i, 1, n, 1) {
		if (s[i] != '1') {
			is1 = 0;
			break;
		}
	}
	if (is1) {
		ans = 1;
		F(i, 2, n, 1) {
			(ans *= i) %= p;
		}
		cout << ans << el;
		r0;
	}
	if (n == m) {
		cout << 0 << el;
		r0;
	}
	if (m == 1) {

		r0;
	}
	dfs(1);
	cout << ans << el;
	r0;
}
