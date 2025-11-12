//CSP 2025 RP++
#include<bits/stdc++.h>
#define int long long
#define gc getchar
#define pc putchar
using namespace std;
const int N = 5005, mod = 998244353;
int n, maxx, size, cnt, a[N], b[N];
template<typename Tp> inline void read(Tp &x){
	x = 0; char c; bool f = false;
	for(c = gc(); !isdigit(c); c = gc()) if(c == '-') f = true;
	for( ; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
	x = f ? -x : x;
}
inline int pow(int x, int y){
	int base = x, res = 1;
	while(y){
		if(y & 1) res = res * base % mod;
		else base = base * base % mod;
		y >>= 1;
	}
	return res;
}
inline void solve1(){
	if(n < 3){ cout << 0 << endl; return ; }
	int ans = pow(2, n);
	ans = (ans - 1 - n) % mod; ans = (ans - n * (n - 1) / 2) % mod;
	cout << (ans + mod) % mod << endl;
}
inline void dfs(int idx){
	if(idx == n + 1){
		if(size < 3) return ;
		int sum = 0, maxx = 0;
		for(int i = 1; i <= size; i++) sum += b[i], maxx = max(maxx, b[i]);
		if(sum > 2 * maxx) cnt++;
		return ;
	}
	b[++size] = a[idx];
	dfs(idx + 1);
	size--;
	dfs(idx + 1);
}
inline void solve2(){
	dfs(1);
	cout << cnt << endl;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	read(n);
	for(int i = 1; i <= n; i++){ read(a[i]); maxx = max(maxx, a[i]); }
	if(maxx == 1) solve1();
	else solve2();
	//cout << ans << endl;
	return 0;
}
