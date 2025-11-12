/*-- Confidence works miracles. --*/
// Time Limit: 1.0 s
// Memory Limit: 512 MB
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef __int128 i128;
#define I inline
#define reg register
typedef pair<int, int> pint;
#define fi first
#define se second
#define mk make_pair

char BG;

namespace FastIO {
	char ibuf[(1<<21)+1], *p1 = ibuf, *p2 = ibuf, obuf[1<<22], *O = obuf;
	#define gh() (((p1==p2)&&(p2=(p1=ibuf)+fread(ibuf,1,1<<21,stdin)),p1==p2)?EOF:*p1++)
	I int read() {
		reg int x = 0, sgn = 1;
		reg char c = gh();
		while (!isdigit(c)) (c=='-')&&(sgn=-1), c = gh();
		while (isdigit(c)) x = (x<<3)+(x<<1)+(c^48), c = gh();
		return x*sgn;
	}
	I void putc(char c) { *O++ = c; }
	void write(int x) {
		if (x < 0) *O++ = '-', x = -x;
		if (x > 9) write(x/10);
		*O++ = x%10+'0';
	}
	I void flush() {
		fwrite(obuf, O-obuf, 1, stdout);
		O = obuf;
	}
}
using namespace FastIO;

constexpr int N = 505;
constexpr int MOD = 998244353;
#define add(a,b) (a+=b)>=MOD&&(a-=MOD)

int n, m, c[N];
string s;

namespace S20 {
	int dp[2][1<<18][18], pcnt[1<<18];
	void solve() {
		memset(dp, 0xcf, sizeof dp);
		dp[0][0][0] = 1;
		for (int i = 1; i < 1<<n; i++) pcnt[i] = pcnt[i>>1]+(i&1);
		for (int i = 1, t = 1; i <= n; i++, t ^= 1) {
			memset(dp[t], 0, sizeof dp[t]);
			for (int S = 0; S < (1<<n); S++) {
				if (pcnt[S] != i-1) continue;
				for (int j = 0; j <= i-1; j++) {
					if (!dp[t^1][S][j]) continue;
					for (int k = 0; k < n; k++) {
						if (S&(1<<k)) continue;
						if (s[i-1] == '1') {
							if (i-1-j >= c[k+1]) {
								add(dp[t][S|(1<<k)][j], dp[t^1][S][j]);
							} else {
								add(dp[t][S|(1<<k)][j+1], dp[t^1][S][j]);
							}
						} else {
							add(dp[t][S|(1<<k)][j], dp[t^1][S][j]);
						}
					}
				}
			}
		}
		int rst = 0;
		for (int i = m; i <= n; i++) add(rst, dp[n&1][(1<<n)-1][i]);
		cout << rst;
	}
}

char ED;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n <= 18) {
		S20::solve();
	} else if (m == n) {
		bool flg = true;
		for (int i = 1; i <= n; i++) {
			if (s[i-1] == '0' || !c[i]) flg = false;
		}
		if (!flg) cout << 0;
		else {
			int rst = 1;
			for (int i = 1; i <= n; i++) rst = (i64)rst*i%MOD;
			cout << rst;
		}
	}
	
	return 0;
}
/*
Expectation: 24 pts
Log: - s 全为 1 没时间打了。。。 
*/
