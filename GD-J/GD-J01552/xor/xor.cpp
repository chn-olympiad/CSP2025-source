#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
long long n, k, a[maxn];
bool vis[maxn];

bool check(long long x, long long y) {
	for (long long i = x; i <= x + y; i++) {
		if (vis[i]) return false;	
	}
	return true;
}

void solve2() {
	int pre[maxn];
	long long ans = -1, cnt = 0;
	for (long long i = 1; i <= n; i++) {
		pre[i] = a[i];
		if (pre[i] == k) {
			cnt++;
			vis[i] = true;
		}
	}
//	}
//	ans = cnt;
//	while (n--) {
//		long long count = 0;
//		for (int i = 1; i <= n; i++) {
//			pre[i] = pre[i] ^ pre[i + 1];
//			if (pre[i] == k) count++;
//		}
//		ans = max(ans, count);
//	}
//	cout << ans << endl; 
/*
2 1 0 3
i = 1: 3 1 3
i = 2: 2 2
i = 3: 0
*/
	ans = cnt;
	for (long long i = 1; i <= n; i ++) {
		for (long long j = 1; j <= n - i; j++) {
			pre[j] = pre[j] ^ a[j + i];
		}
		for (long long j = 1; j <= n - i; j++) {
			if (pre[j] == k && check(j, i)) {
				ans++;
				for (long long k = j; k <= j + i; k++) {
					vis[k] = true;	
				}
			}
		}
	}
	cout << ans << endl;
}

void solve() {
	cin >> n >> k;
	bool f = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 1) f = false;
	}
//	if (n == 1) {
//		if (a[n] == k) cout << 1 << endl;
//		else cout << 0 << endl;
//		return ;
//	} else if (f && k <= 1) {
//		int cnt0 = 0, cnt1 = 0;
//		for (int i = 1; i <= n; i++) {
//			if (a[i] == 1) cnt1++;
//			else cnt0++;
//		}
//		if (k == 1) {
//			cout << cnt1 << endl;
//			return ;	
//		} else if (k == 0) {
//			for (int i = 1; i <= n; i++) {
//				if (a[i] == 1 && a[i + 1] == 1) {
//					cnt0++;
//					i++;
//				} else if (a[i] == 0) {
//					continue;	
//				}
//			}
//			cout << cnt0 << endl;
//			return ;
//		}
//	}
	solve2(); 
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	solve();
}
