#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define inl inline
#define rep(i,l,r) for(ri i = l;i <= r; i ++)
#define per(i,r,l) for(ri i = r;i >= l; i --)
#define N 505
#define mod 998244353
int n, m;
string s;
int c[N];
int a[N], vis[N];
inl bool check(){
	int res = 0;
	rep(i, 1, n){
		if(res >= c[a[i]]) res ++;
		else{
			if(s[i - 1] == '0') res ++;
		}
		if(n - res < m) return 0;
	}
	return (n - res) >= m;
}
int ans;
inl void dfs(int id){
	if(id == n + 1){
		if(check()) ans ++, ans %= mod;
		return ;
	}
	rep(i, 1, n){
		if(!vis[i]){
			vis[i] = 1;
			a[id] = i;
			dfs(id + 1);
			vis[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	rep(i, 1, n) cin >> c[i];
	dfs(1);
	cout << ans % mod;
	return 0;
}
