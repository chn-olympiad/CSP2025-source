#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 998244353;
int n, m;
ll ans;
string s;
ll count(ll x){
	if(x == 1) return 1;
	return (count(x-1)*x)%MOD;
}
int main(){
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	int k = m;
	cin >>s;
	for(int i = 1,c;i <= n; i++){
		cin >> c;
		if(c == 0) m--;
	}
	if(m != k) m++;
	for(ll i = m;i <= n; i++){
		ans += count(i);
		ans %= MOD;
	}
	cout << ans%MOD;
	return 0;
} 
//mengCtulemengka mengCCtulemengCka dadiguayamekaodigua yikuaiqiannengmaisaer
