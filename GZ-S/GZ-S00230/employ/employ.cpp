//GZ-S00230  遵义市第四中学 李星宸 

#include <bits/stdc++.h>
using namespace std;
long long n, m;
string s;
bool _flag = true;
long long c[1000];
long long ans;
long long mod;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	cin >>s;
	mod = 998244353;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		if(c[i] == 0){
			_flag = false;
		}
	}
	if(n == m){
		if(_flag){
			ans = 1;
			for(int i = 1; i <= n; i++){
				ans = ans * i;
				ans = (ans + mod) % mod;
			}
			cout << ans;
		}else{
			cout << 0;
		}
	}
	cout << 0;
	return 0;
}
