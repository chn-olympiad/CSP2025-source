#include <bits/stdc++.h>
#include <set>
#define M 998244353

using namespace std;

int len[5005], n, sum[5005], now[5005], ans;

set<string> se;

int cmp(int a, int b) {
	return a < b;
}

void dp(int x, int l) {
	if (l > n) {
		return;
	}
	for (int i = l; i < n; i++) {
		now[i] = 1;
		int sum = 0, sumid = 0;
		x++;
		if (x >= 3) {
			string s = "";
			for (int i = 0; i < n; i++) {
				if (now[i]) {
					sum += len[i];
					s = s + (char)(i + '0');
					sumid = i;
				}
			}
			int L = se.size();
			se.insert(s);
			if (se.size() != L) {
				if (sum > len[sumid] * 2) {
					ans = (ans + 1) % M;
				}
			}
			
		}
		dp(x + 1, sumid + 1);
		x--;
		now[i] = 0;
	}
	dp(x, l + 1);
}

int main() {
freopen("polygon.in", "r", stdin);
freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> len[i]; 
	}
	sort(len, len + n);
	dp(0, 0);
	cout << ans << endl;
	return 0;
}