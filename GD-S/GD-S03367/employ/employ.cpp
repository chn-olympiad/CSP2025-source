#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505,mod = 998244353;
int n,m,c[N],p[20],ans,jc[N];
string s;
void dfs(int now,int lu){
	if(n - now + 1 < m - lu) return;
	if(lu >= m){
		ans = (ans + jc[n - now + 1]) % mod;
		return;
	}
	if(now == n + 1) return;
	for(int i = 1; i <= n; i++){
		if(!p[i]){
			p[i] = 1;
			if(now - 1 - lu < c[i] && s[now] == '1') dfs(now + 1,lu + 1);
			else dfs(now + 1,lu);
			p[i] = 0;
		}
	}
}
void subtask1(){
	dfs(1,0);
	cout << ans << '\n';
}
void subtaks2(){
	int tg = 1;
	for(int i = 1; i <= n; i++) if(s[i] == '0') tg = 0;
	for(int i = 1; i <= n; i++) if(c[i] == 0) tg = 0;
	if(tg) cout << jc[n] << '\n';
	else cout << 0 << '\n';
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	jc[0] = 1;
	for(int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
	if(m == n){
		subtaks2();
		return 0;
	} 
	subtask1();
	return 0;
	/*
	if(tg){
		subtask2();
		return 0;
	}
	if(n == m){
		subtask3();
		return 0;
	}
	if(m == 1){
		subtask4();
		return 0;
	}
	*/
	return 0;
}
