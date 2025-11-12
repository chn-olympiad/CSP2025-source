#include<bits/stdc++.h>
#define int long long
#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define per(i, j, k) for(int i = (j); i >= (k); --i)
#define repl(i, j, k, l) for(int i = (j); (k); i = (l))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pii pair<int, int>
#define MP pair<int, int>
#define EB emplace_back
#define PB push_back
#define lson p << 1
#define rson p << 1 | 1
#define fir first
#define sec second
using namespace std;
const int MXSIZE = 1 << 20;
char *P1(0), *P2(0), BUFFER[MXSIZE];
#define gtc() (P1 == P2 && (P2 = (P1 = BUFFER) + fread(BUFFER, 1, MXSIZE, stdin), P1 == P2) ? EOF : *P1++)
#define pc putchar
inline int R(){
	int x; char c; bool f = 0;
	while(!isdigit(c = gtc())) if(c == '-') f = 1;
	x = c ^ '0';
	while(isdigit(c = gtc())) x = (x << 3) + (x << 1) + (c ^ '0');
	return f ? ~x + 1 : x;
}
inline void O(int x){
	if(x < 0) pc('-'), x = -x;
	if(x < 10) pc(x + '0');
	else O(x / 10), pc(x % 10 + '0');
}
inline void out(int x, int type = 2){
	O(x);
	if(type == 1) pc(' ');
	if(type == 2) pc('\n');
}
inline void OI(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
}
const int mod = 998244353;
const int N = 510;
inline int ksm(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1) ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}
int fac[N], inv[N], n, m, a[N], p[N], vis[N], ans;
string s;
void dfs(int now){
	if(now == n + 1){
		int cnt = 0, cnt2 = 0;
		rep(i, 1, n){
			if(cnt >= a[p[i]]){++cnt; continue;}
			if(s[i] == '0') ++cnt;
			else if(s[i] == '1') ++cnt2;
		}
		ans += (cnt2 >= m);
		return;
	}
	rep(i, 1, n){
		if(!vis[i]){
			vis[i] = 1;
			p[now] = i;
			dfs(now + 1);
			vis[i] = 0;
		}
	}
}
inline void solve(){
	cin >> n >> m >> s;
	s = "$" + s;
	int cnt = 0, cnt2 = 0;
	rep(i, 1, n) cnt += s[i] == '1', cin >> a[i], cnt2 += a[i] > 0;
	sort(a + 1, a + n + 1);
	if(n <= 10){
		dfs(1);
		cout << ans << '\n';
	}else if(m == n){
		if(cnt < n || cnt2 < n) return cout << 0 << '\n', void();
		else{
			ans = 1;
			rep(i, 1, n) ans = (ans * i) % mod;
			return cout << ans << '\n', void();
		}
	}else{
		ans = 1;
		rep(i, n - m + 1, n) ans = (ans * i) % mod;
		cout << ans << '\n';
	}
}
signed main(){
	 OI();
	 IOS;
	// int cas = R();
	int T = 1;
	// T = R();
	while(T--) solve();
	return 0;
}


