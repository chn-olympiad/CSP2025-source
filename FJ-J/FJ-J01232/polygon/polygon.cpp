#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
const int mod = 998244353;
int n;
int a[maxn];
int qz[maxn];
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	qz[0] = 0;
    int mx = -999;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i];
		mx = max (mx , a[i]);
		qz[i] = a[i] + qz[i - 1];
	}
	long long ans = 0;
	if (n < 3){
		cout << 0;
		return 0;
	}
	if (n == 3){
		if (qz[3] > 2 * mx) cout << 1;
		else cout << 0;
		return 0;
	}
	if (n == 4){
	    
	}
	if (mx == 1){
		cout << 1;
	} 
	return 0;
}
