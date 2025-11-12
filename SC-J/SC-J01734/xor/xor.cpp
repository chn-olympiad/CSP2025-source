#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], sum[N];
bool check(int mid) {
	int cnt = 0, now = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = now; j < i; ++j) {
			if ((sum[i] ^ sum[j]) == k) {
				now = i;
				++cnt;
				break;
			}
		}
	}
	return cnt >= mid;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	int l = 0, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid))	l = mid + 1;
		else	r = mid - 1;
	}
	cout << r;
	return 0;
}