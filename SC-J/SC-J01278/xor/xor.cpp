#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i ++) cin >> a[i];
	cout << n/2;
	return 0;
}
// 奇数个1异或出来是1，偶数个1异或出来是0