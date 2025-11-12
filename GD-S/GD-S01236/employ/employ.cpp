#include <bits/stdc++.h>
 
using namespace std;
using cint = const int;
using LL = long long;
using cLL = const long long;

#define N 505
#define base 127
#define mod 998244353
#define inf 1000000007

const double eps = 1e-9;
const double PI = acos(-1.0);

int n, m;
char s[N];
int c[N];

LL ans = 0ll;

int ch[N];
bool vis[N];
void dfs(cint p) {
	if (p == n + 1) {
		int num = 0;
		for (int i = 1, fail = 0; i <= n; ++i) {
			if (s[i] == '0') {
				++fail;
				continue;
			}
			cint res = fail < c[ch[i]];
			num += res;
			fail += !res;
		}
		(ans += num >= m) %= mod;
		return;
	}
	for (int i = 1; i <= n; ++i)
		if (vis[i] == false) {
			ch[p] = i;
			vis[i] = true;
			dfs(p + 1);
			vis[i] = false;
		}
	return;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	scanf("%s", s + 1);
	bool all = true;
	for (int i = 1; i <= n; ++i)
		all &= s[i] == '1';
	int f = 0;
	for (int i = 1; i <= n; ++i) cin >> c[i], f += c[i] != 0;
	if (all && n > 10) {
		if (f < m) return cout << 0, 0;
		auto fact = [](int x) -> LL {
			LL res = 1ll;
			for (; x; x--)
				res = res * x % mod;
			return res;
		};
//		auto mod_pow = [](LL a, LL b = mod - 2ll) -> LL {
//			LL res = 1ll;
//			for (; b; b >>= 1, a = a * a % mod)
//				if (b & 1) res = res * a % mod;
//			return res;
//		};
		LL ans = fact(n);
		cout << ans << '\n';
		return 0;
	} 
	dfs(1);
	cout << ans << '\n';
	return 0;
}
