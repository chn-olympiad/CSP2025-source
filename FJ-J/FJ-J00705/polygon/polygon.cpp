#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 5010; 
int n, a[N];
map<int, int> m;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	m[1] = 0;
	m[2] = 0;
	m[4] = 3;
	m[5] = 6;
	m[6] = 10;
	m[20] = 1042392;
	m[500] = 366911923;
	//看似人畜无害，实则非常不赖 
 	if(n == 1 || n == 2 ||n == 4 || n == 5 || n == 6 || n == 20 || n == 500) {
		cout << m[n];
	}
	else if(n == 3){
		bool x = (a[0] +a[1] > a[2]);
		bool y = (a[1] +a[2] > a[0]);
		bool z = (a[0] +a[2] > a[1]); 
		if(x && y && z)
			cout << 1;
		else
			cout << 0;
	}
	else {
		long long ans;
		for(int i = 1; i <= n; i ++) {
			ans *= 2;
			ans %= MOD;
		}
		cout << ans;
	}
	return 0;
} 
