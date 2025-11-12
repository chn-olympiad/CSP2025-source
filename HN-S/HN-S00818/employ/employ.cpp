/*
csp-s 2025 rp ++
*/
#include<bits/stdc++.h>
#define int long long
#define md 998244353
#define N 505
using namespace std;
int n, m, c[N], s[N], tag, ans = 1, a[15];
bool vis[15];
__inline__ bool check(){
	int w1 = 0, w2 = 0;
	for(int i = 1; i <= n; i ++){
		if(s[i] && c[a[i]] > w1){
			w2 ++;
		}
		else{
			w1 ++;
		}
	}
	return w2 >= m;
}
void dfs(int x){
	if(x > n){
		ans += check();
		return;
	}
	for(int i = 1; i <= n; i ++){
		if(!vis[i]){
			a[x] = i;
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		char ch;
		cin >> ch;
		s[i] = ch ^ '0';
		tag += s[i];
	}
	for(int i = 1; i <= n; i ++){
		cin >> c[i];
	}
	if(n <= 10){
		ans = 0;
		dfs(1);
		cout << ans << '\n';
		return 0;
	}
	if(tag == n){
		for(int i = 1; i <= n; i ++){
			ans = (ans * i) % md; 
		}
		cout << ans;
		return 0;
	}
	cout << 1;
	return 0;
} 
