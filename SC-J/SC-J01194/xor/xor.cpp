#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
int a[500005];
int vis[2000005];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	int sum = 0;
	int q = 1;
	int res = 0;
	vis[0] = q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum ^= a[i];
		if (vis[sum^k] == q) {
			res++;
			q++;
		}
		vis[sum] = q;
	}
	cout << res << '\n';
	return 0;
}