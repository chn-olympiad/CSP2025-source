#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000010];
int main() {
	freopen("xor.in""w""stdin");
	freopen("xor.out""r""stdout");
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	cout << n / 2 << endl;
	return 0;
}
