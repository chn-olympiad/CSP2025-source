#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N = 3e6 + 100;
int const M = 998244353;
bool check(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0') return false;
	}
	return true;
}
int n, m;
int jc[501], ans, vis[N], a[N];
string s;
void dfs(int cg, int tt){
	if(cg >= m){
		ans = (ans + jc[n-cg-tt]) % M;
		return;
	}
	if(cg + tt > n) return;
	if(n - tt < m) return;
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		//cout << "Ñ¡Ôñ " << i << " a[i] = " << a[i] << endl;
		int ntt = tt;
		int ncg = cg;
		if(tt >= a[i]) ntt++;
		else if(s[cg+tt] == '0') ntt++;
		else ncg++;
		dfs(ncg, ntt);
		vis[i] = 0;
	} 
}

bool pd(){
	for(int i = 1; i <= m; i++) if(!a[i]) return 0;
	return 1; 
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	jc[0] = 1;
	for(int i = 1; i <= n; i++) {
		jc[i] = jc[i-1]*i%M; 
	}
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(m == n){
		if(!check(s)) cout << 0;
		if(!pd()) cout << 0;
		else {
			cout << jc[n];
		}
		return 0;
	}
	
	dfs(0, 0);
	cout << ans; 
	return 0;
}
