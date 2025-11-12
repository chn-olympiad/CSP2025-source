#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
#define int long long
int d[505],c[505];
int ans = 0;
bool use[505];
int n,m;
void dfs(int cur,int go){
	if(cur == n + 1){
		if(go <= n - m){
			ans++;
			ans %= mod;
		}
		return;
	}
	for(int i = 1;i <= n;i++){
		if(use[i]) continue;
		if(go >= c[i] || d[cur] == 0){
			if(go + 1 > n - m) continue;
			use[i] = true;
			dfs(cur + 1,go + 1);
			use[i] = false;
		}
		else{
			use[i] = true;
			dfs(cur+1,go);
			use[i] = false;
		}
	}
}
void work(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		char ch;
		cin >> ch;
		d[i] = ch - '0';
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	dfs(1,0);
	cout << ans % mod;
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		work();
		if(t) cout << endl;
	}
}

