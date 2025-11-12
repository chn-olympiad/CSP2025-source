#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define per(i, l, r) for(int i = l; i >= r; i--)
ll read(){
	ll res = 0, flg = 1; char c = getchar();
	for(; c > '9' || c < '0'; c = getchar()) if(c == '-') flg = -flg;
	for(; c >= '0' && c <= '9'; c = getchar()) res = (res << 3) + (res << 1) + c - '0';
	return res * flg;
}
void write(ll x, char c = '\n'){
	if(x < 0) putchar('-'), x = -x;
	static int stk[35]; int top = 0;
	do { stk[top++] = x % 10; x /= 10; } while(x);
	while(top) { putchar(stk[--top] + '0'); }
	putchar(c);
}
const int N = 2e5 + 5;

int n, q;
string s[N][2];
int len[N];

namespace SUB5{
	const int N = 2005;
	const ll base = 19491001;
	const ll mod1 = 1e9 + 9;
	const ll mod2 = 1e9 + 21;
	pair<ll, ll> pw[N];
	void init_pw(int n){
		pw[0] = {(ll)1, (ll)1};
		rep(i, 1, n){
			pw[i].first = pw[i - 1].first * base % mod1;
			pw[i].second = pw[i - 1].second * base % mod2;
		}
	}
	unordered_map<ll, int> mp1;
	unordered_map<ll, int> mp2;
	void init(){
		rep(i, 1, n){
			pair<ll, ll> hsh1 = {0, 0}, hsh2 = {0, 0};
			per(j, len[i], 1){
//				cerr << i << ' ' << j << ' ' << s[i][0][j] << "----fdbhsfs\n";
				hsh1.first = (hsh1.first * base + (s[i][0][j] - 'a')) % mod1;
				hsh1.second = (hsh1.second * base + (s[i][0][j] - 'a')) % mod2;
				
				hsh2.first = (hsh2.first * base + (s[i][1][j] - 'a')) % mod1;
				hsh2.second = (hsh2.second * base + (s[i][1][j] - 'a')) % mod2;
//			cerr << hsh1.first << ' ' << hsh1.second << " | " << hsh2.first << ' ' << hsh2.second << '\n';
			}
//			cerr << hsh1.first << ' ' << hsh1.second << " | " << hsh2.first << ' ' << hsh2.second << '\n';
			mp1[(hsh1.first << 32) + hsh1.second] = i;
			mp2[(hsh2.first << 32) + hsh2.second] = i;
		}
	}
	
	pair<ll, ll> hsh1[N], hsh2[N];
	
	ll qpow(ll a, int b, ll mod){
		ll res = 1;
		while(b){
			if(b & 1) res = res * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		return res;
	}
	void solve(){
		string t1, t2;
		cin >> t1 >> t2;
		int len = t1.size();
		t1 = '&' + t1, t2 = '&' + t2;
		int L = len, R = -1;
		rep(i, 1, len){
			if(t1[i] != t2[i]){
				L = min(L, i);
				R = max(R, i);
			}
		}
//		cerr << L << ' ' << R << '\n';
		hsh1[0] = {0, 0}, hsh2[0] = {0, 0};
		hsh1[len + 1] = {0, 0}, hsh2[len + 1] = {0, 0};
		per(i, len, 1){
			hsh1[i].first = (hsh1[i + 1].first * base + (t1[i] - 'a')) % mod1;
			hsh1[i].second = (hsh1[i + 1].second * base + (t1[i] - 'a')) % mod2;
			
			hsh2[i].first = (hsh2[i + 1].first * base + (t2[i] - 'a')) % mod1;
			hsh2[i].second = (hsh2[i + 1].second * base + (t2[i] - 'a')) % mod2;
		}
		ll ans = 0;
		rep(l, 1, L){
			rep(r, R, len){
				pair<ll, ll> res = {((hsh1[l].first - hsh1[r + 1].first * pw[r - l + 1].first) % mod1 + mod1) % mod1, 
										((hsh1[l].second - hsh1[r + 1].second * pw[r - l + 1].second) % mod2 + mod2) % mod2};
				pair<ll, ll> res2 = {((hsh2[l].first - hsh2[r + 1].first * pw[r - l + 1].first) % mod1 + mod1) % mod1, 
										((hsh2[l].second - hsh2[r + 1].second * pw[r - l + 1].second) % mod2 + mod2) % mod2};
				
//				cerr << l << ' ' << r << ' ' << res.first << " | " << res.second << '\n';
				
				if(!mp1.count((res.first << 32) + res.second)) continue;
				if(!mp2.count((res2.first << 32) + res2.second)) continue;
				if(mp1[(res.first << 32) + res.second] == mp2[(res2.first << 32) + res2.second]) ans++;
			}
		}
		write(ans);
	}
}
signed main(){
	#ifndef MY_JUDGE
		freopen("replace.in", "r", stdin);
		freopen("replace.out", "w", stdout);
	#endif
	
	#ifdef MY_JUDGE
//		freopen("replace2.in", "r", stdin);
//		freopen("my.out", "w", stdout);
	#endif
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> q;
	rep(i, 1, n){
		cin >> s[i][0] >> s[i][1];
		len[i] = s[i][0].size();
		s[i][0] = '&' + s[i][0];
		s[i][1] = '&' + s[i][1];
	}
	if(n <= 2000){
		SUB5::init_pw(2000);
		SUB5::init();
		while(q--){
			SUB5::solve();
		}
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/


