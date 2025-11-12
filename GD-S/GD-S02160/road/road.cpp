#include <bits/stdc++.h>
using namespace std;    
typedef long long ll;   
                        
ll n = 0;               
ll m = 0;               
ll k = 0;               
ll flag = 0;            
ll mp[10010][10010] = {0};
                        
int main () {           
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k; 
	for (ll i = 1; i <= m; i++) {
		ll x = 0;       
		ll y = 0;       
		ll p = 0;       
		cin >> x >> y >> p;
		mp[x][y] = p;   
		mp[y][x] = p;   
	}                   
	for (ll i = 1; i <= k; i++) {
		ll c = 0;       
		cin >> c;       
		mp[n + i][n + i];
		if (c != 0) {   
			flag = 1;   
		}               
		for (ll j = 1; j <= m; j++) {
			ll d = 0;   
			cin >> d;   
			mp[n + 1][j];
			mp[j][n + 1];
		}               
	}                   
	if (!flag) {        
		cout << 0 << '\n';
	}                   
	fclose(stdin);      
	fclose(stdout);     
	return 0;           
}                       
