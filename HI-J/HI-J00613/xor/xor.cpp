#include<bits/stdc++.h>
using namespace std;
int a[100005];
int ans = 0;
int kans(int l, int r) {
	int x = a[l];
	for(int i = l+1; i <= r; i++) {
		x = x ^ a[i];
	}
	return x;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, l = 1;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			if(kans(i, j) == k) {
				ans++;
			}
		}
	}
	cout << ans;
	
	return 0;
}
