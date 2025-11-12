#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+10;
int a[MAXN],n,k,ans,mx = 1;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j >= mx ; j --) {
			int p = a[j];
			for (int h = j+1; h <= i; h ++) p = p^a[h];
			if (p == k) {
				ans ++, mx = i+1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

