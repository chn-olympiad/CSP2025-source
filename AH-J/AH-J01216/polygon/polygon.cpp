#include <bits/stdc++.h>
using namespace std;
int a[10010];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	int c = 0;
	while(c + 3 <= n) {
		for(int i = 0;i < n+c-1;i++) {
			int cnt = 0, mx = -1;
			for(int j = 1 + i;j <= c + 3;j++) {
				cnt += a[j];
				mx = max(mx, a[j]);
			}
			if(cnt>2*mx) {
				ans++;
			}
		}
		c++;
	}
	cout << ans+1;
	return 0;
}
//qingshuruwenbeng
