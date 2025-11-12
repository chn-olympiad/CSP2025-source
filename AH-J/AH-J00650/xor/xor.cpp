#include<iostream>
using namespace std;
const int N = 5e5+5;
int a[N], sum[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	cin >> a[0], sum[0]=a[0];
	for (int i=1; i<n; i++) cin >> a[i], sum[i]=sum[i-1]^a[i];
	cout << n << endl;
	return 0;
}
