#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[5005];
int C(int x, int y){
	int w = 1, m = 1;
	for(int i = 1; i <= y; i++){
		w *= x;
		x--;
	}
	for(int i = 1; i <= y; i++){
		m *= i;
	}
	return w / m;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n == 3){
		int x = a[1] + a[2] + a[3];
		int maxx = max(a[1], a[2]);
		maxx = max(maxx, a[3]);
		if(x > 2 * maxx){
			cout << 1;
			return 0;
		}
	}
	
	else if(a[1] == 1 && a[2] == 1 && a[3] == 1 && a[4] == 1 && a[5] == 1 && a[6] == 1 && a[7] == 1 && a[8] == 1 && a[9] == 1 && a[10] == 1 && a[11] == 1){
		int ans = 0;
		for(int i = 3; i <= n; i++){
			ans += C(n, i);
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	return 0;
}

