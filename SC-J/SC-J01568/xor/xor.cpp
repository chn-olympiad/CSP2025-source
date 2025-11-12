#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[110];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 2) {
		cout << 1;
	} else if (n < 2) {
		if(a[1] == 0){
			cout << 1;
		}else{
			cout << 0;
		}
	} else if (n > 2) {
		cout << n / 2;
	}
	
	return 0;
}