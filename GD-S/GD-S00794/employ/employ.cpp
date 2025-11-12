#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f;
const long long mod = 998244353;
#define ll long long 

int n , m , c[510];
string s;

int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.in" , "w" , stdout);
	cin >> n >> m;
	cin >> s;
	int cnt = 0;
	for(int i = 1 ; i <= n ; i++){
		scanf("%d" , &c[i]);
		if(c[i] == 0) cnt++;
	}
	ll ans = 0;
	bool f = 1;
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] == '0') f = 0;
	}
	int r = n - cnt; 
	if(f == 1 && r >= m){
		ans = 1;
		for(int i = 1 ; i <= n ; i++){	
			ans = (ans * i) % mod;
			//cout << ans % mod << endl;
		}
		cout << ans % mod << endl;
		return 0;
	}else {
		cout << 0 << endl;
		return 0;
	} 
	return 0;
}

/*


Ren5Jie4Di4Ling5%
*/
