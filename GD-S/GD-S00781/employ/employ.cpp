#include<bits/stdc++.h>
using namespace std;
#define int long long
#define accept 0
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(n == m){
		string s;
		cin >> s;
		for(int i =0;i < s.size();i++){
			if(s[i] == '0'){
				cout << 0;
				return accept;
			}
		}
		cout << 1;
	}
	int ans = 1,n1 = 0;
	string s;
	cin >> s;
	for(int i =1;i <= n ;i ++){
		int x;
		cin >> x;
		if(x == 0) n1++;
	}
	if(n-n1 < m){
		cout << 0;
		return 0;
	}
	for(int i = n;i >= 1;i--){
		ans *= i;
		ans %= 998244353;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return accept;
}
