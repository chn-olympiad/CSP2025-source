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
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
}
const int N = 1e5 + 10;
int n, s[N][4], cnt[4], mx[N], se[N], a[4], th[N], idx[N];
bool cmp(int x, int y){
	return a[x] > a[y];
}
bool cmp2(int x, int y){
	if(s[x][mx[x]] - s[x][se[x]] == s[y][mx[y]] - s[y][se[y]]) return s[x][se[x]] - s[x][th[x]] > s[y][se[y]] - s[y][th[y]];
	return s[x][mx[x]] - s[x][se[x]] > s[y][mx[y]] - s[y][se[y]];
}
inline void solve(){
	n = R(); cnt[1] = cnt[2] = cnt[3] = 0;
	rep(i, 1, n){
		idx[i] = i;
		int tmp[4];
		rep(j, 1, 3) a[j] = s[i][j] = R(), tmp[j] = j;
		sort(tmp + 1, tmp + 4, cmp);
		mx[i] = tmp[1], se[i] = tmp[2]; th[i] = tmp[3];
  	}
  	sort(idx + 1, idx + n + 1, cmp2);
	int ans = 0;
	rep(id, 1, n){
		int i = idx[id];
		if(cnt[mx[i]] < n / 2) ++cnt[mx[i]], ans += s[i][mx[i]];
		else if(cnt[se[i]] < n / 2) ++cnt[se[i]], ans += s[i][se[i]];
		else if(cnt[th[i]] < n / 2) ++cnt[th[i]], ans += s[i][th[i]];
	}
	out(ans);
}
signed main(){
	 OI();
	// int cas = R();
	int T = 1;
	T = R();
	while(T--) solve();
	return 0;
}


