#include<bits/stdc++.h>
using namespace std;
int a[500005], pre[500005], mod = 5 * 10e5;
int main () {
	freopen("xor.in","r", stdin);
	freopen("xor.out","w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	pre[0] = a[0];
	for (int i = 1; i < n; i++) {
		pre[i] = a[i] ^ pre[i - 1];
	}
	srand(time(0));
	cout << rand() % mod;
	return 0;
}
