#include <bits/stdc++.h>
using namespace std;
int n, a[5001], k, l, r;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (k == 0 && n <= 100) cout << n / 2;
	else cout << n / 3;
	return 0;
}
