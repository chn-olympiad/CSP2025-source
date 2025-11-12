#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 505;
const LL P = 998244353;
int n, m, c[N];
char s[N];
void solve2(){
	int cnt = 0;
	for(int i = 1; i <= n; ++i) cnt += (c[i] == 0);
	if(n - m < cnt) cout << 0 << endl;
	else{
		LL res = 1;
		for(LL i = 2; i <= n; ++i) res = res * i % P;
		cout << res << endl;
	} 
}
LL ans;
int p[N];
bool vis[N];
void dfs(int cur){
	if(cur > n){
		int cnt = 0;
		for(int i = 1; i <= n; ++i)
			if(cnt >= c[p[i]] || s[i] == '0') cnt++; 
		if(n - m >= cnt) ans++;
		ans %= P;
		return ; 
	}
	for(int i = 1; i <= n; ++i){
		if(vis[i]) continue;
		p[cur] = i;
		vis[i] = 1;
		dfs(cur + 1);
		vis[i] = 0;
	}
}
void solve1(){
	dfs(1);
	cout << ans << endl;
}
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
	cin >> n >> m >> s + 1;
	for(int i = 1; i <= n; ++i) cin >> c[i];
	if(n < 20) solve1();
	else solve2();
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
