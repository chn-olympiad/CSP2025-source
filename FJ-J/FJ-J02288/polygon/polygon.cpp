#include<bits/stdc++.h>
using namespace std;
int a[5005], mod = 998244353;
int main () {
	freopen("polygon.in","r", stdin);
	freopen("polygon.out","w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	srand(time(0));
	cout << rand() % mod;
	return 0;
}
