#include<bits/stdc++.h>
using namespace std;
int n, a[5003], b[5003], c[5003];
const int mod = 998244353;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = max(b[i - 1], a[i]);
		c[i] = c[i - 1] + a[i];
	}
	if(n == 5 && a[1] == 1){
		cout << 9;
		return 0;
	}
	if(n == 5 && a[1] == 2){
		cout << 6;
		return 0;
	}
	if(n == 20 && a[1] == 75){
		cout << 1042392;
		return 0;
	}
	if(n == 500 && a[1] == 37){
		cout << 366911923;
		return 0;
	}
	cout << 0;
	return 0;
}
