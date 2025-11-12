#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 0; i < (1 << n); i++) {
		if(__builtin_popcount(i) < 3)continue;
		int sum = 0, maxn = 0;
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				sum += a[j], maxn = max(a[j],maxn);
			}
		}
		if(sum > 2 * maxn)ans++;
	}
	cout << ans;
}

