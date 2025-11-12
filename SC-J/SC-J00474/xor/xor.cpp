#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000000];
int s1, s0;
int vis[1000000];
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (k == 1 && a[i] == 1) {
			s1++;
		}
		else if (k == 0) {
			if (a[i] == 0) {
				s0++;
			}
			else if (!vis[i] && !vis[i + 1]) {
				if (a[i] == 1 && a[i + 1] == 1) {
					s0++;
					vis[i] = 1;
					vis[i + 1] = 1;
				}
			}
		}
	}
	if (k == 1) {
		cout << s1;
	}
	else if (k == 0) {
		cout << s0;
	}
	else {
		cout << n;
	}
	return 0;
}