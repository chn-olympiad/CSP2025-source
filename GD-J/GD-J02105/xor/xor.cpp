#include <bits/stdc++.h>
#define fo(i, a, b) for(int i = a; i <= b; i ++)

using namespace std;

const int N = 5e5 + 1e4 + 5;

int n, k;

int a[N];

int vis[N], arr[N], tot;

signed main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;

	int now = 0, ans = 0;
	vis[0] = 1;
	tot = 1;
	arr[1] = 0;
	fo(i, 1, n) {
		cin >> a[i], now ^= a[i];
		while(vis[now ^ k]) {//while
			if(tot) {
				ans ++, now = 0;
				fo(j, 1, tot)
					vis[arr[j]] = 0;
			}
			tot = 0;
//			vis[0] = 1;
			continue;
		}
		vis[now] = 1, arr[++ tot] = now;
	}

	cout << ans << "\n";

	return 0;
}

