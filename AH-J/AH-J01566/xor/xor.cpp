#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, k, ans, a[N], sum[N], vis[N], cnt;
map <long long, long long> x;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	cout << (n % 2 == 1 ? (n - 1) / 2 : n / 2);
	return 0;
}
