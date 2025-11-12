#include<iostream>
#include<cstring>
using namespace std;
const int mod = 998244353;
int n, m, c[505], cnt = 0, maxc = 0;
string s;
int main(){
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		maxc = max(maxc, c[i]);
		if(c[i] == 0) cnt++;
	}
	if(cnt > n - m){
		cout << 0;
		return 0;
	}
	if(m == 1){
		int j;
		for(int i = 1; i <= n; i++){
			if(s[i] == '1') j = i;
		}
		if(j <= maxc){
			int ans = 1;
			for(int i = n - 1; i > 0; i--) ans = ans * n % mod;
			cout << ans;
		}
		else{
			cout << 0;
		}
	}
	else{
		int ans = 1;
		for(int i = n; i > 0; i--) ans = ans * n % mod;
		cout << ans;
	}
	return 0;
} 
