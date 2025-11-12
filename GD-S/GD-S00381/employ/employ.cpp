#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; ++i)
#define _req(i, x, y) for(int i = x; i >= y; --i)
#define fi first
#define se second
#define mst(f, i) memset(f, i, sizeof f)
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr);
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
namespace fastio{
	template<typename T> inline void read(T &t){
		T x = 0, f = 1;
		char c = getchar();
		while(!isdigit(c)){
			if(c == '-') f = -f;
			c = getchar();
		}
		while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
		t = x * f;
	}
	template<typename T, typename ... Args> inline void read(T &t, Args &...args){
		read(t), read(args...);
	}
	void write(int x){printf("%d", x);}
	void writes(int x){printf("%d ", x);}
	void writeln(int x){printf("%d\n", x);}
	void write(ll x){printf("%lld", x);}
	void writes(ll x){printf("%lld ", x);}
	void writeln(ll x){printf("%lld\n", x);}
}
using namespace fastio;
#define multitest() int T; read(T); for(int tCase = 1; tCase <= T; ++tCase)
const int N = 505, _ = 500;
const ll mod = 998244353;
void add(ll &x, ll y){x = (x + y) % mod;}
void add(int &x, int y){x += y; if(x > mod) x -= mod;}
void mul(ll &x, ll y){x = x * y % mod;}
int n, m, c[N], cnt[N], suf[N];
char ch[N];
ll f[2][N][N];//pre i has k, [i+1,n] ok j
ll C[N][N], fac[N];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	fac[0] = fac[1] = 1; _rep(i, 2, _) fac[i] = fac[i - 1] * i % mod;
	_rep(i, 0, _) _rep(j, 0, i) C[i][j] = !j ? 1 : (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	read(n, m), scanf("%s", ch + 1);
	_rep(i, 1, n) read(c[i]), cnt[c[i]]++;
	_rep(i, 0, n - m) f[n & 1][0][i] = 1;
	_req(i, n, 0) suf[i] = suf[i + 1] + cnt[i];
	_req(i, n, 1){
		int c = i & 1;
		_rep(j, 0, n - i){
			_rep(k, 0, i){
				if(!f[c][j][k]) continue;
				if(ch[i] == '1'){
					if(suf[k + 1] > j) add(f[c ^ 1][j + 1][k], f[c][j][k] * (suf[k + 1] - j));
					_rep(t, 0, cnt[k]){
						if(t > n - i - j) break;
						add(f[c ^ 1][j + t][k - 1], f[c][j][k] * C[n - i - j][t] % mod * C[cnt[k]][t] % mod * fac[t] % mod);
					}
				}else{
//					add(f[i - 1][j + 1][k - 1], f[i][j][k] * (suf[k + 1] - j));
					_rep(t, 0, cnt[k]){
						if(t <= n - i - j + 1)
						add(f[c ^ 1][j + t][k - 1], f[c][j][k] * C[n - i - j + 1][t] % mod * C[cnt[k]][t] % mod * fac[t] % mod);
						if(t <= n - i - j && suf[k + 1] > j)
						add(f[c ^ 1][j + t + 1][k - 1], f[c][j][k] * C[n - i - j][t] % mod * C[cnt[k]][t] % mod * fac[t] % mod * (suf[k + 1] - j) % mod);
					}
					
				}
			}
		}
		_rep(j, 0, n - i) _rep(k, 0, i) f[c][j][k] = 0;
	}
//	debug("%d %d\n", f[2][1][1], f[1][2][0]);
	ll ans = f[0][n - cnt[0]][0] * fac[cnt[0]] % mod;
	writeln(ans);
	return 0;
}
/*
3 2
101
1 1 2

*/
