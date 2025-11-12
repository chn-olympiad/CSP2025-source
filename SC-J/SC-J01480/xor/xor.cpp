#include <bits/stdc++.h>
using namespace std;

int n, k, l, r, ans = 0, lst_r;
int cnt[30][2], a[500005], s[500005];

void add(int x, int targ) {
	int y = 0;
	while (x > 0) {
		cnt[y][1] += (x & 1) * targ, cnt[y][0] += (!(x % 2)) * targ;
		x >>= 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
		s[i] = s[i - 1] ^ a[i];
		add(a[i], 1);
	}
	
	if (k <= 1) {
		if (k == 1){
			int ans__ = 0;
			for (int i = 1; i <= n; ++i) ans += a[i];
			cout << ans;
			return 0;
		} else {
			int ans__ = 0;
			int cnt__ = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i] == 1) cnt__++;
				else {
					ans__ += cnt__ / 2;
					cnt__ = 0;
					ans__++;
				}
			} ans__ += cnt__ / 2;
			cout << ans__;
			return 0;
		}
	}
	
	
	return 0;
}