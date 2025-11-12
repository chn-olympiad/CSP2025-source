#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define db double
#define str string
#define MP make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ms(a,t) memset(a,t,sizeof(a))
#define lowbit(x) ((x)&(-(x)))
const int maxn = 500+5;
const int maxm = 2e5+10;
const ll INF = 0x3f3f3f3f;
const db eps = 1e-6;
const int mod = 998244353;
int n,m;
char s[maxn];
int a[maxn];
int c[maxn][maxn];
int f[maxn][maxn][maxn];
int cnt[maxn],pre[maxn];
void inc(int &x,int y) {
	x += y-mod; x += ((x>>31)&mod);
}
int C(int x,int y) {
	if(x < y || x < 0 || y < 0) return 0;
	return c[x][y];
}
ll fp(ll x,ll y) {
	ll ret = 1;
	while(y > 0) {
		if(y&1) ret = ret *x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ret;
}
ll fac[maxn],inv[maxn];
ll A(int x,int y) {
	return fac[x] * inv[x-y] % mod;
}
void Solve() {
	cin >> n >> m;
	fac[0] = 1; for(int i = 1; i <= n; i++) fac[i] = fac[i-1] * i % mod;
	inv[n] = fp(fac[n],mod-2); for(int i = n-1; i >= 0; i--) inv[i] = inv[i+1] * (i+1) % mod;
	for(int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			c[i][j] = c[i-1][j];
			inc(c[i][j],c[i-1][j-1]);
		}
	}
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
//		ans = ans * cnt[a[i]] % mod;
	}
	pre[0] = cnt[0]; for(int i = 1; i <= n; i++) pre[i] = cnt[i] + pre[i-1];
	f[0][0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			for(int k = 0; k <= i && k <= pre[j]; k++) if(f[i][j][k]) {
				ll cnt0 = pre[j]-k;// number that remain and less than or equal to j
				ll e = i-k; // places that will greater than j before i
				if(s[i+1] == '0') {
					for(int x = 0; x <= cnt[j+1] && x <= e; x++) {
//						cerr<<i<<' '<<j<<' '<<k<<' '<<x<<' '<<i+1<<' '<<j+1<<' '<<k+x+1<<' '<<cnt0<<'\n';
						inc(f[i+1][j+1][k+x+1],f[i][j][k]*A(e,x)%mod*C(cnt[j+1],x)%mod*cnt0%mod); // put a number <= j at position i+1
					}
					for(int x = 0; x <= cnt[j+1] && x <= e+1; x++) {
//						cerr<<' '<<i<<' '<<j<<' '<<k<<' '<<x<<' '<<i+1<<' '<<j+1<<' '<<k+x<<' '<<A(e+1,x)<<'\n';
						inc(f[i+1][j+1][k+x],f[i][j][k]*A(e+1,x)%mod*C(cnt[j+1],x)%mod); // put a number > j at position i+1
					}
				} else {
					for(int x = 0; x <= cnt[j+1] && x <= e; x++) {
//						if(x >1) cerr<<"  "<<i<<' '<<j<<' '<<k<<' '<<x<<' '<<i+1<<' '<<j+1<<' '<<k+x+1<<' '<<cnt0<<' '<<A(e,x)<<' '<<f[i][j][k]*cnt0*A(e,x)<<'\n';
						inc(f[i+1][j+1][k+x+1],f[i][j][k]*cnt0%mod*A(e,x)%mod*C(cnt[j+1],x)%mod); // put x "j+1" before i,and a number <= j at i+1
					}
					inc(f[i+1][j][k],f[i][j][k]); // decide to left a space for a number greater than j
				}
			}
		}
	}
	/*
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k <= n; k++) {
				cerr<<f[i][j][k]<<' ';
			}
			cerr<<'\n';
		}
		cerr<<'\n';
	}
	*/
	ll ans = 0;
	for(int i = n; i >= 0; i--) {
		for(int j = 0; j <= n-m; j++) {
			if(pre[j] == i) {
//				cerr<<i<<' '<<j<<' '<<n<<' '<<f[n][j][i]<<' '<<fac[n-i]<<' '<<f[n][j][i]*fac[n-i]<<'\n';
				ans = (ans + f[n][j][i] * fac[n-i]) % mod;
			}
		}
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	cerr<<(sizeof(f)+sizeof(c))/1024.0/1024<<'\n';
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	int tt; cin >> tt; while(tt--)
	Solve();
	return 0;
}
