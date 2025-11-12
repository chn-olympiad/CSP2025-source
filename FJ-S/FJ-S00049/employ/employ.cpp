#include <bits/stdc++.h>
using namespace std;
#define IC isdigit(c)
#define GC c=getchar()
#define il inline
il void rd(auto &x) { char GC; x = 0; bool f = 0;
	for (; !IC; GC) f |= x == '-';
	for (; IC; GC) x = x * 10 + (c - 48);
	f && (x = -x);
}
il void rd(auto &x, auto &...y) { rd(x); rd(y...);
}
#define U(i,l,r) for (int i(l),END##i(r); i<=END##i; ++i)
#define D(i,l,r) for (int i(l),END##i(r); i>=END##i; --i)
#define ms(x, v) memset(x, v, sizeof(x))
#define vc vector
#define pb push_back
#define eb emplace_back
using ll = long long;

const ll P = 998244353;
const int N = 505;
ll qpow(ll x, ll t = P - 2) { ll v = 1;
	for (; t; (x *= x) %= P, t >>= 1) if (t & 1)
		(v *= x) %= P;
	return v;
}
ll fac[N], ifac[N];
void gen() {
	fac[0] = 1; U (i, 1, N - 1) fac[i] = fac[i - 1] * i %P;
	ifac[N - 1] = qpow(fac[N - 1]); D (i, N - 1, 1) ifac[i - 1] = ifac[i] * i %P;
}
il ll A(int n, int m) {
//	if (m > n || m < 0) assert(0);
	return fac[n] * ifac[n - m] %P;
}
il ll C(int n, int m) {
//	if (m > n || m < 0) assert(0);
	return fac[n] * ifac[m] %P * ifac[n - m] %P;
}
il void I(ll &x, ll v) { (x += v) %= P; }

int n, m; char a[N]; int c[N];

il void check(int &x, int v) {
//	if (x == -1) x = v;
//	else assert(x == v);
	x = v;
}

/*
	freopen("employ4.in", "r", stdin);
*/
/*
	随机说话之 
	我们看云，从四月回暖后冷空气再次到来，到十月某次秋雨后；此时云暂别。我们认为
	此时的云和冬季覆盖整个8/8天空的水泥块有本质区别：边界锐利，时刻准备着
	酝酿一场暴雨。于是我们奋不顾身，冲向云所谓的边界。而边界从来只是被 d^6 控制的
	尺度，不可触及。于是人类在没有察觉到边界之前进入云底。在任意一个时刻，暴雨来临，
	只好撑起一把不得不撑的伞。 
*/

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	gen();
	
	rd(n, m); scanf("%s", a + 1); U (i, 1, n) rd(c[i]);
	sort(c + 1, c + n + 1); U (i, 1, n) a[i] -= '0';
	int sum0 = 0;
	U (i, 1, n) sum0 += !a[i];
	int pres0[N] {};
	U (i, 1, n) pres0[i] = pres0[i - 1] + (!a[i]);
	
	int cnt[N] {}, suf[N] {}, pre[N] {}; // c_i >= j 的人有 suf_j 个
	U (i, 1, n) ++cnt[c[i]], ++suf[c[i]];
	D (i, n, 0) suf[i] += suf[i + 1];
	U (i, 1, n + 1) pre[i] += pre[i - 1];
	 
	ll f[N][N] {}; int g[N][N]; ms(g, -1);
	// 前 i 天已经确定，直到第 i 天有 j 个人未被录取，有 k 个人的 ci 需要 > j 但未确定是谁，有 z 个人已经知道自己未录取但未被填 
	
	f[0][0] = 1; g[0][0] = cnt[0];
	U (i, 0, n - 1) {
		ll F[N][N] {}; int G[N][N]; ms(G, -1);
		
//		clog << "@" << i << endl;
		U (j, 0, min(i, n - m)) U (k, 0, i - j) if (f[j][k]) {
			int z = g[j][k]; assert(z != -1);
			// 第 i 天过去后，所有 c 在 [0,j] 的人的情况：z 唯一 
			// 1. 第 i+1 天未录取 
			if (!a[i + 1]) { // 放一个任意人 
				U (l, 0, min(k, cnt[j + 1])) { // c=j+1 的由一定能录取变为一定不能录取 
					ll coef = A(cnt[j + 1], l) * C(k, l) %P;  // 选人；选位置 
					I(F[j + 1][k - l], f[j][k] * coef);
					check(G[j + 1][k - l], z + (cnt[j + 1] - l));
				}
			} else { // 放一个 c<=j 的 
				// 前面还需要 k 个 ci > j 的。
				// 枚举选用 c=j+1 的个数
				if (z) {
					U (l, 0, min(k, cnt[j + 1])) {
						ll coef = A(cnt[j + 1], l) * C(k, l) %P * z %P;
						I(F[j + 1][k - l], f[j][k] * coef);
						check(G[j + 1][k - l], z + (cnt[j + 1] - l) - 1);
						// cnt[j+1] 剩下的 cnt[j+1]-l 个人将未被录取，等待未录取选用
					}
				}
				I(F[j][k + 1], f[j][k]);
				check(G[j][k + 1], z);
			}
		}
		memcpy(f, F, sizeof(F));
		memcpy(g, G, sizeof(G));
	}
	
	// 会有最后一段
	ll ans = 0;
	U (j, 0, n - m) U (k, 0, n) if (f[j][k]) {
		if (k > suf[j + 1])
			break;
		int z = g[j][k]; assert(z != -1);
		
		ll coef = A(suf[j + 1], k); 
		I(ans, f[j][k] * coef);
	}
	(ans *= fac[sum0]) %= P;
	
	cout << ans << endl;
}
