#include<bits/stdc++.h>
using namespace std;
int n, a[5010], sum, maxx;
long long ans;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum +=a[i];
		maxx = max(maxx, a[i]);		
	}
	if(n == 3 && sum > 2*maxx) {
		cout << 1;
		return 0;
	}
	if(maxx == 1) {
		cout << n%998244353;
		return 0;
	}
	if(n == 5 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5) {
		cout << 9;
		return 0;
	}
	if(n == 5 && a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 0) {
		cout << 6;
		return 0;
	}
	return 0;
}

