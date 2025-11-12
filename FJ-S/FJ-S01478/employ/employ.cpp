#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll mod = 998244353;
const ll N = 505;

int n,m;
string s;
int c[N];
bool can[N];
ll fac[N];
ll ans;

void dfs2(int now,int give,int d){
	if(now == n){
		if(d >= m) ans++;
		ans %= mod;
		return ;
	}
	if(n - now + d < m) return;
	if(d == m){
		ans += fac[n - now - 1];
		ans %= mod;
	}
	for(int i = 1; i <= n; i++){
		if(!can[i]){
			can[i] = 1;
			if(s[now] == '0' || give >= c[i]) dfs2(now + 1,give + 1,d);
			else dfs2(now + 1,give,d + 1);
			can[i] = 0;
		}
	}
}

void dfs(int now,int give,int d){
	if(now == n){
		if(d >= m) ans++;
		ans %= mod;
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(!can[i]){
			can[i] = 1;
			if(s[now] == '0' || give >= c[i]) dfs(now + 1,give + 1,d);
			else dfs(now + 1,give,d + 1);
			can[i] = 0;
		}
	}
}

void init(){
	fac[0] = 1,fac[1] = 1;
	for(int i = 2; i <= 500; i++){
		fac[i] = fac[i - 1] * i;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(n <= 11)	dfs(0,0,0);
	else dfs2(0,0,0);
	cout << ans << "\n";
	return 0;
}

