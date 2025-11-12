#include<bits/stdc++.h>
using namespace std;
constexpr int N = 505;
constexpr int mod = 988244353;
int vis[N] , d[N] , c[N];
int n , m , ans;
string s;
void check(){
	int ccd = 0;
	int lq = 0;
//	for(int i = 1 ; i <= n ; i++){
//		cout << c[d[i]] << " " ;
//	}
//	cout << endl;
	for(int i = 1 ; i <= n ; i++){
		if(c[d[i]] <= ccd ){
			ccd++;
			continue;
		}
		if(s[i] == '1'){
			lq++;
		}
		else{
			ccd++;
		}
	}
//	cout << lq << endl;
	if(lq >= m){
		ans++;
		ans %= mod;
	}
}
void dfs(int cur){
	if(cur == n +1){
		check();
	}
	for(int i = 1 ; i <= n ; i++){
		if(vis[i]) continue;
		d[cur] = i;
		vis[i] = true;
		dfs(cur + 1);
		vis[i] = false;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for(int i = 1 ; i <= n ; i++){
		cin >> c[i];
	}
	dfs(1);
	cout << ans << endl;
}
