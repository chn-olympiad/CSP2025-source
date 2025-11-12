#include<bits/stdc++.h>
using namespace std;
const int N = 510, mod = 998244353;
namespace cza{
	int m, n;
	char s[N];
	int c[N];
	int vis[N];
	int tmp[N];
	int ans = 0;
	void dfs(int now){
		if(now == n + 1){
			int cc = 0;
			for(int i = 1; i <= n; i++){
				if(cc >= c[tmp[i]] or s[i] == '0'){
					cc++;
				}
			}
			if(n - cc >= m) ans++;
			return ;
		}
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				tmp[now] = i;
				vis[i] = 1;
				dfs(now + 1);
				vis[i] = 0;
			}
		}
	}
	int main(){
		freopen("employ.in", "r", stdin);
		freopen("employ.out", "w", stdout);
		ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
		cin >> n >> m;
		cin >> (s + 1);
		for(int i = 1; i <= n; i++){
			cin >> c[i];
		}
		if(n <= 10){
			dfs(1);
			cout << ans;
			return 0;
		}
		if(m == n){
			for(int i = 1; i <= n; i++){
				if(s[i] == '0' or c[i] == 0){
					cout << 0;
					return 0;
				}
			}
			int jie = 1;
			for(int i = 1; i <= n; i++){
				jie = 1ll * jie * i % mod;
			}
			cout << jie;
			return 0;
		}
		int jie = 1;
		for(int i = 1; i <= n; i++){
			jie = 1ll * jie * i % mod;
		}
		cout << jie;
		return 0;
	}
}
signed main(){
	return cza::main();
}
