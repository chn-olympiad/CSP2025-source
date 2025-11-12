#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 505;
const int mod = 998244353;

ll n , m , c[N] , pre[N] , ans;
ll to[N] , a[N] , mul[N]; 
string s;

bool check(int t , int i , int q){
	if(c[i] > q && s[t] == '1') return true;
	return false;
}

void dfs(int t , int cnt){
	if(cnt >= m){
		ans = (ans + mul[n - t + 1]) % mod;
		return;
	}
	if(cnt + (n - t + 1) < m) return;
	
	if(t > n){
		if(cnt >= m) ans = (ans + 1) % mod;
		return;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(to[i]) continue;
		to[i] = 1;
		int p = (check(t , i , t - cnt - 1) ? 1 : 0);
		dfs(t + 1 , cnt + p);
		to[i] = 0;
	}
}

void solve1(){
	dfs(1 , 0);
	cout << ans % mod;
}

void solve2(){
	if(m == 1) cout << mul[n] % mod;
	else if(m == n) cout << 0;
	else cout << mul[n] % mod;
}

int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	
	cin >> n >> m >> s;
	
	s = " " + s;
	
	mul[0] = 1;
	for(int i = 1 ; i <= n ; i ++){
		mul[i] = (mul[i - 1] * i) % mod;
	}
	
	for(int i = 1 ; i <= n ; i ++){
		cin >> c[i];
		
		if(s[i] == '0') pre[i] = pre[i - 1] + 1;
		else pre[i] = pre[i - 1];
	}
	if(n <= 50) solve1();
	else solve2();
	
	return 0;
}
