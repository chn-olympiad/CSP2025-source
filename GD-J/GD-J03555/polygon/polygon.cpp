#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 50;

int a[N], n, value, sum[N], k;

void dfs(int x, int ma, int s, int num) {
	if(num >= 3 && ma * 2 < s) {
		value ++;
		value = value % 998244353;
	}

	if(x == n + 1 || ma * 2 >= s + sum[n] - sum[x - 1]) return ;

	for(int i = x; i <= n; ++ i) {
		dfs(i + 1, max(ma, a[i]), s + a[i], num + 1);
	}
}

int qpow(int x) {
	int res = 1, t = 2;
	while(x) {
		if(x & 1) {
			res = res * t % 998244353; 
		}
		t = t * t % 998244353;
		x >>= 1; 
	}
	
	if(res == 1) return 1;
	
	return res;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		if(a[i] <= 1) k ++;
	}

	if(k == n) {
		for(int i = 1; i <= n; ++ i) {
			if(a[i] == 0) {
				sum[i] = sum[i - 1] + 1;
			} else {
				sum[i] = sum[i - 1];
			}
		}

		for(int j = 4; j <= n; j ++) {
			for(int i = 1; i <= n - j + 1 - sum[n] + sum[i - 1]; ++ i) {
				value = (value + (n - j + 2 - i - sum[n] + sum[i - 1]) * (qpow((sum[n] - sum[i - 1])))) % 998244353;
			}
		}

	}

	else {
		dfs(1, 0, 0, 0);
	}

	cout << value;
	return 0;
}
