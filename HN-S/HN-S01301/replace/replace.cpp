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
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
}
//map<string, string> ma;
int n, q;
inline void solve(){
	cin >> n >> q;
	rep(i, 1, n){
		string s, t;
		cin >> s >> t;
//		ma[s] = t;
	}
	while(q--){
		int ans = 0;
		string s, t;
		cin >> s >> t;
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


