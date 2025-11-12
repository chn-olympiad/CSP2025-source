#include <bits/stdc++.h>
using namespace std;
int a[1111];
int ans = 0;
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int oi = 0;
	for(int i = 0; i < n; i++){
		if(s[i] -'0' == 0){
			oi++;
		}
	}
	if(n-oi < m){
		cout << 0;
		return 0;
	}
	if(m == n){
		for(int i = 0; i < s.size(); i--){
			if(s[i]-'0' == 0){
				cout << 0;
				return 0;
			}
		}
		for(int i = 1; i <= n; i++){
			if(a[i] != 0){
				ans++;
			}
		}
		long long sum = ans;
		while(ans--){
			if(ans == 0){
				break;
			}
			sum = sum * ans % 998244353;
		}
		cout << sum;
		return 0;
	}
	if(m == 1){
		for(int i = 1; i <= n; i++){
			if(a[i] != 0){
				ans++;
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		if(s[i] -'0' == 1){
			ans++; 
		}
	}
	if(ans == n){
		long long sum = ans;
		while(ans--){
			if(ans == 0){
				break;
			}
			sum = sum * ans % 998244353;
		}
		cout << sum;
	}
	return 0;
}
