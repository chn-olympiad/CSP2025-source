#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define per(i, j, k) for(int i = (j); i >= (k); i --)
#define pb emplace_back
#define fi first
#define se second
using vi = vector<int>;
using pi = pair<int, int>;

template<typename T0, typename T1> bool chmin(T0 &x, const T1 &y){
	if(y < x){x = y; return true;} return false;
}
template<typename T0, typename T1> bool chmax(T0 &x, const T1 &y){
	if(x < y){x = y; return true;} return false;
}

template<typename T> void debug(char *s, T x){
	cerr << s <<" = "<< x << endl;
}
template<typename T, typename ...Ar> void debug(char *s, T x, Ar... y){
	int dep = 0;
	while(!(dep == 0 && *s == ',')){
		if(*s == '(') dep ++;
		if(*s == ')') dep --;
		cerr << *s ++;
	}
	cerr << " = " << x << ",";
	debug(s + 1, y...);
}
#define gdb(...) debug((char*)#__VA_ARGS__, __VA_ARGS__)

using u32 = uint32_t;
using u64 = uint64_t;
constexpr int mod = 998244353;
struct mint{
	u32 x;

	mint(): x(0){}
	mint(int _x){
		if((_x %= mod) < 0) _x += mod;
		x = _x;
	}
	u32 val()const {
		return x;
	}
	mint qpow(int y = mod - 2)const {
		mint x = *this, res = 1;
		while(y){
			if(y % 2) res *= x;
			x *= x;
			y /= 2;
		}
		return res;
	}
	mint& operator += (const mint &B){
		if((x += B.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator -= (const mint &B){
		if((x -= B.x) >= mod) x += mod;
		return *this;
	}
	mint& operator *= (const mint &B){
		x = u64(x) * B.x % mod;
		return *this;
	}
	mint& operator /= (const mint &B){
		return *this *= B.qpow();
	}
	friend mint operator + (const mint &A, const mint &B){
		return mint(A) += B;
	}
	friend mint operator - (const mint &A, const mint &B){
		return mint(A) -= B;
	}
	friend mint operator * (const mint &A, const mint &B){
		return mint(A) *= B;
	}
	friend mint operator / (const mint &A, const mint &B){
		return mint(A) /= B;
	}
	mint operator - ()const {
		return mint() - *this;
	}
};

const int N = 505;
mint fac[N], ifac[N];
void init(){
	fac[0] = ifac[0] = 1;
	rep(i, 1, N - 1){
		fac[i] = fac[i - 1] * i;
		ifac[i] = ifac[i - 1] / i;
	}
}
mint C(int m, int n){
	return n < 0 || n > m? 0: fac[m] * ifac[n] * ifac[m - n];
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	init();
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vi cnt(n + 2);
	rep(i, 0, n - 1){
		int x;
		cin >> x;
		cnt[x] ++;
	}

	vi tot(n + 2);
	rep(i, 0, n + 1){
		tot[i] = accumulate(cnt.begin(), cnt.begin() + min(i + 1, n + 2), 0);
	}

	mint ans = 0;
	vector< vector< vector<mint> > > f(2, 
		vector< vector<mint> >(n + 2, 
		vector<mint>(n + 2)));

	f[0][0][0] = 1;
	bool o = 0;
	rep(i, 0, n){
		rep(j, 0, n){
			int nxt = j;
			while(nxt < n && s[nxt] == '1'){
				nxt ++;
			}

			// (j - l) + r == tot[i]

			if(i <= n - m && nxt == n){
				int l = j - tot[i];
				if(l >= 0 && f[o][j][l].val()){
					mint val = f[o][j][l];
					int sum = accumulate(cnt.begin(), cnt.begin() + i + 1, 0);
					sum = n - sum;
					rep(k, i + 1, n + 1){
						val *= C(sum, cnt[k]);
						sum -= cnt[k];
					}
					ans += val;
				}
			}

			rep(l, 0, n){
				int r = tot[i] - (j - l);
				if(!f[o][j][l].val()){
					continue;
				}
				if(nxt != n){
					rep(dl, 0, cnt[i + 1]){
						if(l + (nxt + 1 - j) - dl >= 0){
							f[o ^ 1][nxt + 1][l + (nxt + 1 - j) - dl] += f[o][j][l] * C(l + (nxt + 1 - j), dl) * C(r + (cnt[i + 1] - dl), r);
						}
						if(l + (nxt - j) - dl >= 0 && r > 0){
							f[o ^ 1][nxt + 1][l + (nxt - j) - dl] += f[o][j][l] * C(l + (nxt - j), dl) * C(r - 1 + (cnt[i + 1] - dl), (r - 1));
						}
					}
				}
				if(r > 0){
					rep(k, j + 1, nxt){
						rep(dl, 0, cnt[i + 1]){
							if(dl > l + (k - 1 - j)){
								continue;
							}
							f[o ^ 1][k][l + (k - 1 - j) - dl] += f[o][j][l] * C(l + (k - 1 - j), dl) * C(r - 1 + (cnt[i + 1] - dl), r - 1);
						}
					}
				}
				f[o][j][l] = mint();
			}
		}
		o ^= 1;
	}
	rep(i, 0, n){
		ans *= fac[ cnt[i] ];
	}
	cout << ans.val() <<'\n';
}
