#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXX = 1e5 + 5, M = 998244353;

int n, m, flag, c[MAXX], sum0, s[MAXX], ans, vis[MAXX];
char a[MAXX];

void dfs(int x){
	if(x == n + 1){
		int num = 0, sum = 0;
		for(int i = 1; i <= n; i++){
			if(sum >= c[s[i]] || a[i] == '0'){
				sum++;
			}else{
				num++;
			}
		}
		if(num >= m) ans = (ans + 1) % M;
		return;
	} 
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			vis[i] = 1;
			s[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	flag = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		flag &= (a[i] == '1');
	} 
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		if(c[i] == 0) sum0++;
	}
	if(m == n){
		ans = 1;
		if(!flag || sum0) ans = 0;
		for(int i = n; i >= 1; i--){
			ans = (ans * i) % M;
		}
		cout << ans;
	}else{
		dfs(1);
		cout << ans << '\n';
	}
	return 0;
} //cute zrr±£ÓÓ 
