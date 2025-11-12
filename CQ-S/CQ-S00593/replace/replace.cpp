//luogu uid 755230 jzc114514
//25
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define fs first
#define se second
#define pii pair<int, int>
#define lp (p * 2)
#define rp (p * 2 + 1)
#define all(s) s.begin(), s.end()
using namespace std;
inline void cmax(int &a, int b){if(a < b)a = b;}
inline void cmin(int &a, int b){if(a > b)a = b;}
const int N = 2e4 + 25, H = 5e3 + 5;
struct Hashing{
	int h[H] = {}, b[H] = {};
	void ycl(string s, int n, int base, int mod){
		b[0] = 1;
		for(int i = 1; i <= n; i ++){
			b[i] = b[i - 1] * base % mod;
			h[i] = (h[i - 1] * base + s[i]) % mod;
		}
	}
	int qr(int l, int r, int base, int mod){
		return ((h[r] - h[l - 1] * b[r - l + 1]) % mod + mod) % mod;
	}
};
int B[3] = {13331, 131, 257};
int M[3] = {1000000007, 1000000009, 998244353};
struct HSH{
	Hashing h[3] = {};
	void ycl(string s, int n){
		for(int i = 0; i < 3; i ++)
			h[i].ycl(s, n, B[i], M[i]);
	}
	pair<int, pii> qr(int l, int r){
		if(r < l)return {0LL, {0LL, 0LL}};
		return {h[0].qr(l, r, B[0], M[0]),
				{h[1].qr(l, r, B[1], M[1]), h[2].qr(l, r, B[2], M[2])}};
	}
};
void print(string a, int l, int r){
	for(int i = l; i <= r; i ++)cout << a[i];
	cout << "\n";
}
void pf(int a){
	cout << a << " ";
}
void pf(pair<int, pii>a){
	cout << a.fs << " " << a.se.fs << " " << a.se.se << " ";
}
int qd(string s, int n, int b, int m){
	int h = 0;
	for(int i = 1; i <= n; i ++)
		h = (h * b + s[i]) % m;
	return h;
}
void solve(){
	int n, q;;
	cin >> n >> q;
	pair<int, pii> da[N] = {}, db[N] = {};
	int lena[N] = {}, lenb[N] = {};
	for(int i = 1; i <= n; i ++){
		string s, ss;
		cin >> s >> ss;
		lena[i] = s.size(), lenb[i] = ss.size();
		int l = s.size();
		s = "#" + s;
		da[i] = {qd(s, l, B[0], M[0]), 
					{qd(s, l, B[1], M[1]), qd(s, l, B[2], M[2])}};
		s = "#" + ss, l = ss.size();
		db[i] = {qd(s, l, B[0], M[0]), 
					{qd(s, l, B[1], M[1]), qd(s, l, B[2], M[2])}};
	}
	while(q --){
		string a, b; cin >> a >> b;
//		cout << a << " " << b << "\n";
		int la = a.size(), lb = b.size();
		a = "#" + a, b = "#" + b;
		int ans = 0;
		HSH x, y;
		x.ycl(a, la); y.ycl(b, lb);
		for(int i = 1; i <= n; i ++){
			if(lena[i] - lenb[i] != la - lb)continue;
			for(int j = 1; ; j ++){
				int k = j + lenb[i] - 1, w = j + lena[i] - 1;
				if(k > lb || w > la)break;
				if(y.qr(j, k) == db[i] && x.qr(j, w) == da[i]
					&& y.qr(1, j - 1) == x.qr(1, j - 1) &&
					y.qr(k + 1, lb) == x.qr(w + 1, la))ans ++;
//				cout << k << " " << w << "\n";
//				pf(y.qr(j, k));pf(y.qr(1, j - 1));pf(y.qr(k + 1, lb));
//				cout << "\n";
//				pf(x.qr(j, w));pf(x.qr(1, j - 1));pf(x.qr(w + 1, la));
//				cout << "\n";
//				pf(db[i]); pf(da[i]);
//				cout << "\n";
//				cout << i << " " << j << "\n";
			}
		}
		cout << ans << "\n";
	}
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T --){
		solve();
	}
}

