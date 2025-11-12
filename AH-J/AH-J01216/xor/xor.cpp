#include <bits/stdc++.h>
using namespace std;
int a[10000100];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++) {
		if (a[i] == k)
			cnt++;
	}
	if(k==0) {
		cout << cnt;
		return 0;
	}
	for(int i = 1;i <= n;i++) {
		for(int j = i + 1;j <= n;j++) {
			int ans = a[i];
			for(int l = i + 1;l <= j;l++) {
				ans ^= a[l];
			}
			if (ans == k) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
//I wouldn't.
