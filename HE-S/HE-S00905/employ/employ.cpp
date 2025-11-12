#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int n , m , c[510] , cnt , sum;
string s;

signed main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m >> s;
	for(int i = 1 ; i <= n ; i++) cin >> c[i];
	sort(c + 1 , c + n + 1);
	for(int i = 0 ; i < s.size() ; i++) if(s[i] == '0') cnt++;
	if(cnt >= c[n]){cout << 0; return 0;}
	for(int i = n ; i >= 1 ; i--) if(cnt < c[i]) sum++;
	for(int i = 1 ; i < n ; i++) sum = (sum * (n - i)) % mod;
	cout << sum;
	return 0;
}
 
