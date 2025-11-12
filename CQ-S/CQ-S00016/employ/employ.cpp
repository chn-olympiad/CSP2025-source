#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define lb(x) (x&-x)

namespace rsy {
using namespace std;
using i64 = long long;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
void chmax (int &x, int c) { x = max(x, c); }
void chmin (int &x, int c) { x = min(x, c); }

const int maxn = 5e2 + 10, mod = 998244353;
int N, K; string S;
int val[maxn], p[maxn];
int fac[maxn];

namespace sub1 {
	
	void main() {
		L (i, 1, N) p[i] = i;
		int cnt = 0;
		do {
			string T = S;
			int now = 0;
			L (i, 1, N) {
				if (now >= val[p[i]] && T[i] == '1') T[i] = '0';
				now += (T[i] == '0'); 
			}
			int ct = 0; L (i, 1, N) ct += (T[i] == '1');
			cnt += (ct >= K);
		} while (next_permutation(p + 1, p + 1 + N));
		cout << cnt << '\n';
	}
}

namespace sub2 {
	
	void main() {
		
	}
}

void solve() {
	cin >> N >> K >> S, S = ' ' + S;
	L (i, 1, N) cin >> val[i];
	if (N <= 10) return sub1::main();
	bool F = 1; L (i, 1, N) F &= (S[i] == '1');
	if (F) return sub2::main();
}

signed main() {
	fac[0] = 1; L (i, 1, maxn - 10) fac[i] = 1ll * fac[i - 1] * i % mod;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	while (T--) solve();
	return 0;
}
} signed main() {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	return rsy::main();
}
