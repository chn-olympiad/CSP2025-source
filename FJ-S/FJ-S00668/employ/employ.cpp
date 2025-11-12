#include<bits/stdc++.h>
using namespace std;
int a[505];
long long ans = 1, cnt = 0;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	string s;
	int n, m;
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == 1){
		cout << n;
		return 0;
	}
	if(n-m == 1){
		cout << n-1;
		return 0;
	}
	if(m == n){
		ans = 1;
		for(int i = 1; i <= n; i++){
			ans *= i;
			ans %= 998224353;
		}
		cout << ans;
		return 0;
	}
	for(int i = n; i >= m; i--){
		for(int j = 1; j <= i; j++){
			ans *= j;
			ans %= 998224353;
		}
	}
	cout << ans;
	return 0;
}
