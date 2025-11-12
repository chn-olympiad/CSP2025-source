#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int a[N], s[N]; 
int to[N], cnt[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	long long n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((s[j] ^ s[i - 1]) == k) {
				to[i] = j;
				break; 
			} 
		}
//		cout << to[i] << " ";
	}// 预处理每一个以a[i]开头的最大个数 
//	cout << "\n"; 
	for (int i = n; i >= 1; i--) {
		if (to[i] == 0) {
			cnt[i] = cnt[i + 1];
		} else {
			cnt[i] = max(cnt[i + 1], 1 + cnt[to[i] + 1]);
		}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << cnt[i] << " ";
//	}
//	cout << "\n"; 
	cout << cnt[1];
	return 0;
} 
