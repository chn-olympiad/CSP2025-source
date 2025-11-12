#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e5 + 5;
int n, k;
int a[MAXN], d[MAXN], r[MAXN], ans[MAXN], l[MAXN], rl[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
		d[i] = d[i - 1] ^ a[i];
		
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((d[j] ^ d[i - 1]) == k) {
				cnt++;
				l[cnt] = i;
				rl[j] = i;
				r[cnt] = j;
			} 
		}
	}
	
	ll res = 0;
	for (int i = 1; i <= cnt; i++) {
		int sl = 0, sr = r[i];
		ll ar = 0;
		while(sl <= cnt) {
			sl = upper_bound(l + 1, l + cnt + 1, sr) - l;
			sr = r[sl];
			ar++;
		}
		res = max(res, ar);
	}
	
	cout << res;


	return 0;
}


