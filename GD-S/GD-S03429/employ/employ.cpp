#include<bits/stdc++.h>
using namespace std;
const int M = 998244353, N = 505;
long long ans = 0; 
int n,m,cntt;
int c[N],p[N],val[N];
bool vis[N];
void solve(){
	int cnt = 0;
	for(int i = 1;i <= n;i++)
		if(c[i] == 0) cnt++;
	if(n - cnt >= m){
		long long ans = 1;
		for(int i = 1;i <= n;i++)
			ans = 1ll * ans * i % M;
		cout << ans << '\n';
	}
	else cout << 0 << '\n';
} 
void dfs(int cur){
	if(cur == 0){
		int re = 0, cnt = 0;
		for(int i = 1;i <= n;i++)
			if(p[i] == 1 && re < c[val[i]]){
				cnt++;
			}
			else{
				re++;
			}
		if(cnt >= m) ans++;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = true;
			val[cur] = i;
			dfs(cur - 1);
			vis[i] = false;
			val[cur] = 0; 
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	string s; cin >> s;
	for(int i = 0;i < s.length();i++)
		p[i + 1] = s[i] - '0';
	bool flag = true;
	for(int i = 1;i <= n;i++)
		cin >> c[i];
	for(int i = 1;i <= n;i++){
		if(p[i] != 1) flag = false;
	}
	if(flag) solve();
	else{
		dfs(n); cout << ans << '\n';
	}
}
