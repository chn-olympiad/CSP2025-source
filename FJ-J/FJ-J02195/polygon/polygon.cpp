#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5010];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	if(n < 3){
		cout << "0";
		return 0;
	}
	if(n == 3){
		sort(a + 1, a + 4);
		if(a[1] + a[2] > a[3])cout << "1";
		else cout << "0";  
		return 0;
	}
	sort(a + 1, a + n + 1);
	if(a[n] == 1){
		long long l = 1;
		for(int i = 1; i <= n; i++){
			l = l * 2 % mod;
		}
		l -= 1;
		l -= n;
		l = l - (n - 1) * n / 2;
		if(l < 0)l += mod;
		cout << l;
		return 0; 
	}
	return 0;
}
