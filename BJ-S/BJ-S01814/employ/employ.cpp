#include <bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	if(n == m){
		int len = s.length();
		for(int i = 0;i < len;i++){
			if(s[i] == '0'){
				cout << 0;
				return 0;
			}
		}
		for(int i = 1;i <= n;i++){
			if(!c[i]){
				cout << 0;
				return 0;
			}
		}
		int ans = 1;
		for(int i = 2;i <= n;i++){
			ans *= i;
		}
		cout << ans;
		return 0;
	}
	return 0;
}
