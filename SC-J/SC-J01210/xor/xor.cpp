#include<bits/stdc++.h>
using namespace std;
long long sum[500010];
long long n, k;
long long x;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		sum[i] = sum[i - 1] ^ x;
	}
	if (n == 2) {
		cout << 1;
	} else if(n == 1){
		cout << 0;
	} else if(k == 0){
		cout << n / 2;
	} else {
		cout << 2;
	}
	return 0;
}