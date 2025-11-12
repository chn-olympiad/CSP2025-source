#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5 * 1e5 + 1;
int n, a[MAXN], xora[MAXN] = {0}, k;

bool check(int l, int r) {
	int res = xora[r] ^ xora[l - 1];
	return (res == k); 
}

int answer(int s, int e) {
	int ans = 0;
	int l = s, r = s;
	while (l <= n && r <= e) {
		if (check(l, r)) {
			int nans = 0;
			if (l < r) nans = answer(l + 1, r);
			ans = max(ans + 1, ans + nans);
			l = r + 1;
			r++;
		} else {
			if (r < e) r++;
			else {
				l++;
				r = l;
			}
		}
	}
	return ans;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		xora[i] = a[i] ^ xora[i - 1];
	}
	cout << answer(1, n);
	return 0;
}

