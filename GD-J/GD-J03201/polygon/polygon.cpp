#include<bits/stdc++.h>
#define int long long
const int N = 5e3 + 5;
const int mod = 998244353;
using namespace std;

int C[N][N], n, a[N];

int calc(){
	C[1][0] = C[1][1] = 1;
	for(int i = 2; i <= n; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++){
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
	int sum = 0;
	for(int i = 3; i <= n; i++){
		sum += C[n][i];
		sum %= mod;
	}
	return sum;
}

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if(n == 3){
		int x, y, z;
		cin >> x >> y >> z;
		int maxn = max({x, y, z});
		int s = x + y + z;
		if(s > 2 * maxn) cout << 1;
		else cout << 0;
		return 0;
	}
	cout << calc();
	return 0;
}
