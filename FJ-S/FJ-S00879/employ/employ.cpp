#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[2000];
const long long mod = 998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	bool f = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != '1') f = 1;
	}
	if(!f){
		long long ans = 1,cnt = 0;
		for(int i = 1; i <= n; i++){
			if(c[i] == 0) cnt++;
		}
		for(int i = 1; i <= n - cnt; i++){
			ans = ans * i % mod;
		}
		for(int i = 1; i <= cnt; i++){
			ans = ans * i % mod;
		}
		cout << ans;
		return 0;
	}
	return 0;
} 
