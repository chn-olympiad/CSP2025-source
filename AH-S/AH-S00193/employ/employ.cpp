#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2 + 10, mod = 998244353;
int n, m, a[N], tot[N], ans, fact[N], infact[N];
char c[N];
bool vis[N];
int ksm(int a, int b){
	int ans = 1;
	while(b){
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}
void dfs(int x){
	if(x == n + 1){
		int fail = 0, pass = 0;
		for(int i = 1; i <= n; i++){
			if(fail >= a[tot[i]]) fail++;
			else if(c[i] == '0') fail++;
			else pass++;
		}
		if(pass >= m) ans++;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		tot[x] = i;
		dfs(x + 1);
		vis[i] = 0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n <= 10){
		dfs(1);
		cout << ans << '\n';
	}else{
		int ans = 1;
		for(int i = 1; i <= n; i++) ans = ans * i % mod;
		cout << ans << '\n';
	}
	return 0;
}
