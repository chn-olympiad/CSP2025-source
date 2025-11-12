#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 507, mod = 998244353;
int n, m;
int a[N], b[N];
int jc[N];
int sum;
int vis[N];
int kc(int x){
	if(x >= mod) x -= mod;
	return x;
}
int ans;
void dfs(int x){
//	cout << x << "??\n";
	if(x == n+1){
		int sub = 0;
		for(int i = 1; i <= n; i++){
//			cout << vis[i] << ' ';
			if(!a[i]) sub++;
			else if(sub >= b[vis[i]]) sub++;
		}
//		cout << sub << '\n';
		if(n-sub >= m) ans++;
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = x;
		dfs(x+1);
		vis[i] = 0;
	}
}
signed main(){
	//is long long?
	//The N is enough?
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		char c;
		cin >> c;
		a[i] = c-'0';
		sum += a[i];
	}
	for(int i = 1; i <= n; i++) cin >> b[i];
	if(sum < m){
		cout << 0;
		return 0;
	}else if(sum == n){
		sum = 0;
		for(int i = 1; i <= n; i++) sum += b[i] == 0;
		if(n-sum < m){
			cout << 0;
			return 0;
		}
		int x = 1;
		for(int i = 1; i <= n; i++) x = x*i%mod;
		cout << x;
		return 0;
	}
	jc[0] = 1;
	for(int i = 1; i <= n; i++) jc[i] = jc[i-1]*i%mod;
	dfs(1);
	cout << ans;
	return 0;
} 
