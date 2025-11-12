#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], s[N];
int n, k;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	s[i] = s[i - 1] ^ a[i];
	}
	int mx = -1e9, t = 1;
	for (int k = 1; k <= n; k++) {
		int cnt = 0;
		for (int i = k; i <= n; i++) {
			int x = s[i] ^ s[t - 1];
			if (x == k) {
				cnt++;
				t = i + 1;
			}
		}	
		mx = max(mx, cnt);
	}
	
	cout << mx;
    return 0;
}
