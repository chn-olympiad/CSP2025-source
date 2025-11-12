// 旅人 1969，旅人 1970 —— 看看月亮吧。
#include <bits/stdc++.h>
using namespace std;
#define _rep(i,a,b) for(int i = a; i <= b; ++i)
using ll = long long;
int in(void) { int x; scanf("%d", &x); return x; }
const int kN = 505, p = 998244353;
int n, m, cnt[kN], d[kN], C[kN][kN], A[kN][kN], fac[kN];
char s[kN];
int f[2][kN][kN], pre[kN];
void add(int &x, ll y) { x = (x + y) % p; }
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = in(), m = in();
	fac[0] = 1; _rep(i,1,n) fac[i] = 1ll * fac[i - 1] * i % p;
	C[0][0] = 1; _rep(i,1,n) {
		C[i][0] = C[i][i] = 1;
		_rep(j,1,i - 1) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
	}
	_rep(i,0,n) _rep(j,0,i) A[i][j] = 1ll * C[i][j] * fac[j] % p;
	scanf("%s", s + 1);
	_rep(i,1,n) s[i] -= '0', pre[i] = pre[i - 1] + !s[i];
	_rep(i,1,n) ++cnt[in()];
	d[0] = cnt[0]; _rep(i,1,n) d[i] = d[i - 1] + cnt[i];
	f[0][0][0] = 1; 
	_rep(i,1,n) {
		int lst = (i & 1) ^ 1;
		memset(f[i & 1], 0, sizeof(f[i & 1]));
		_rep(c,pre[i - 1],i - 1) _rep(h,0,i - 1) if(f[lst][c][h]) {
			int v = f[lst][c][h];
			if(!s[i]) {
				_rep(j,0,min(cnt[c + 1],h)) add(f[i & 1][c + 1][h - j], 1ll * v * A[cnt[c + 1]][j] % p * C[h][j]);
			} else {
				add(f[i & 1][c][h + 1], v);
				int cnto = d[c] - (c - pre[i - 1]) - (i - 1 - c - h);
				// assert(cnto >= 0);
				if(cnto < 0) continue; //should never happens
				_rep(j,0,min(cnt[c + 1],h)) 
					add(f[i & 1][c + 1][h - j], 1ll * v * cnto % p * A[cnt[c + 1]][j] % p * C[h][j]);
			}
		}
	}
	int ans = 0;
	_rep(c,0,n - m) _rep(z,0,n) add(ans, 1ll * f[n & 1][c][z] * A[n - d[c]][z]);
	printf("%lld\n", 1ll * ans * fac[pre[n]] % p);
	return 0;
}