#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//#define LOCAL//
namespace IO{
	const int len = 1 << 20;
#ifdef LOCAL
	inline char GC(){return getchar();}
#else
	static char ibuf[len], *iS = ibuf, *iT = ibuf;
	inline char GC(){return iS==iT&&(iT=(iS=ibuf)+fread(ibuf,1,len,stdin),iS==iT)?EOF:*iS++;}
#endif
	template <typename T>
	inline void read(T &x){
		x = 0; bool f = false; char c = GC();
		while(c < '0' || c > '9'){
			f |= (c == '-'); c = GC();
		}
		while(c >= '0' && c <= '9'){
			x = (x << 3) + (x << 1) + (c ^ 48); c = GC();
		}
		if(f) x = ~(x - 1);
	}
	inline int reads(char *s){
		int x = 0; char c = GC();
		while(c < 'a' || c > 'z') c = GC();
		while(c >= 'a' && c <= 'z'){
			s[x++] = c; c = GC();
		}
		return x;
	}
}
using IO::read;
using IO::reads;
const int mod = 998244353;
ll bas = 131;
ull bas2 = 137;
const int mxn = 2e5+10, mxL = 5e6+10;
int n, q, cnt;
char tmp[mxL];
ll pw[mxL];
ull pw2[mxL];
vector<char> a[mxn][2], b[mxn][2];
int na[mxn], nb[mxn], al[mxn], ar[mxn], bl[mxn], br[mxn];
struct Node{
	ll x; ull y;
	bool operator==(const Node u) const{ return x == u.x && y == u.y; }
	Node operator+(const Node u) const{ return {(x + u.x) % mod, y + u.y}; }
	Node operator-(const Node u) const{ return {(x + mod - u.x) % mod, y - u.y}; }
};
Node add(Node u, char c){
	return {(u.x * bas + c) % mod, u.y * bas2 + c};
}
Node lsh(Node u, int i){
	return {u.x * pw[i] % mod, u.y * pw2[i]};
}
vector<Node> ha[mxn][2], hb[mxn][2];
Node qrya(int i, int p, int l, int r){
	l--;
	return ha[i][p][r] - lsh(ha[i][p][l], r - l);
}
Node qryb(int i, int p, int l, int r){
	l--;
	return hb[i][p][r] - lsh(hb[i][p][l], r - l);
}
namespace Sub0{
	void solve(){
		int i, j, x;
		for(i = 1; i <= q; i++){
			if(bl[i] < 0){
				printf("0\n"); continue;
			}else{
				x = 0;
				for(j = 1; j <= n; j++){
					if(al[j] == 0 || ar[j] - al[j] != br[i] - bl[i]) continue;
					if(al[j] > bl[i] || na[j] - ar[j] > nb[i] - br[i]) continue;
					if(qrya(j, 0, 1, na[j]) == qryb(i, 0, bl[i] - al[j] + 1, bl[i] - al[j] + na[j]) && 
					   qrya(j, 1, 1, na[j]) == qryb(i, 1, bl[i] - al[j] + 1, bl[i] - al[j] + na[j])){
						x++;
					}
				}
				printf("%d\n", x);
			}
		}
	}
}
void init(){
	n = 5000000;
	int i;
	for(i = 1, pw[0] = 1, pw2[0] = 1; i <= n; i++){
		pw[i] = pw[i - 1] * bas % mod;
		pw2[i] = pw2[i - 1] * bas2;
	}
}
void solve(){
	cnt = 0;
	int i, j, l;
	read(n); read(q);
	for(i = 1; i <= n; i++){
		na[i] = l = reads(tmp + 1);
		a[i][0].resize(l + 1);
		for(j = 1; j <= l; j++){
			a[i][0][j] = tmp[j];
		}
		l = reads(tmp + 1);
		a[i][1].resize(l + 1);
		for(j = 1; j <= l; j++){
			a[i][1][j] = tmp[j];
		}
	}
	for(i = 1; i <= q; i++){
		nb[i] = l = reads(tmp + 1);
		b[i][0].resize(l + 1);
		for(j = 1; j <= l; j++){
			b[i][0][j] = tmp[j];
		}
		l = reads(tmp + 1);
		b[i][1].resize(l + 1);
		for(j = 1; j <= l; j++){
			b[i][1][j] = tmp[j];
		}
	}
	for(i = 1; i <= n; i++){
		l = a[i][0].size() - 1;
		ha[i][0].resize(l + 1);
		for(j = 1, ha[i][0][0] = {0, 0}; j <= l; j++){
			ha[i][0][j] = add(ha[i][0][j - 1], a[i][0][j]);
		}
		l = a[i][1].size() - 1;
		ha[i][1].resize(l + 1);
		for(j = 1, ha[i][1][0] = {0, 0}; j <= l; j++){
			ha[i][1][j] = add(ha[i][1][j - 1], a[i][1][j]);
		}
	}
	for(i = 1; i <= q; i++){
		l = b[i][0].size() - 1;
		hb[i][0].resize(l + 1);
		for(j = 1, hb[i][0][0] = {0, 0}; j <= l; j++){
			hb[i][0][j] = add(hb[i][0][j - 1], b[i][0][j]);
		}
		l = b[i][1].size() - 1;
		hb[i][1].resize(l + 1);
		for(j = 1, hb[i][1][0] = {0, 0}; j <= l; j++){
			hb[i][1][j] = add(hb[i][1][j - 1], b[i][1][j]);
		}
	}
	for(i = 1; i <= n; i++){
		l = na[i];
		for(j = 1; j <= l; j++){
			if(a[i][0][j] != a[i][1][j]) break;
		}
		if(j <= l){
			al[i] = j;
			for(j = l; j > 0; j--){
				if(a[i][0][j] != a[i][1][j]) break;
			}
			ar[i] = j;
		}else{
			al[i] = ar[i] = 0;
			cnt++;
		}
	}
	for(i = 1; i <= q; i++){
		if(b[i][0].size() != b[i][1].size()){
			bl[i] = br[i] = -1; continue;
		}
		l = nb[i];
		for(j = 1; j <= l; j++){
			if(b[i][0][j] != b[i][1][j]) break;
		}
		if(j <= l){
			bl[i] = j;
			for(j = l; j > 0; j--){
				if(b[i][0][j] != b[i][1][j]) break;
			}
			br[i] = j;
		}else{
			bl[i] = br[i] = 0;
		}
	}
	Sub0::solve();
//	if((n <= 10000 && q <= 10000) || q == 1){
//		Sub0::solve(); return;
//	}
//	if(Sub1::solve()) return;
//	Sub0::solve();
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	init();
	int t = 1;
	while(t--) solve();
	return 0;
}
