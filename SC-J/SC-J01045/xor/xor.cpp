#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
long long a[N];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long s = a[1];
	long long num = 0;
	for (int i = 2; i <= n; i++) {
		if (s == k) {
			num++;
			s = a[i];
		} else {
			s = s^a[i];
		}
	}
	cout << num + 1;
}