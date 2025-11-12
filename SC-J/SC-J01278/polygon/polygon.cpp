#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
const int M = 5010;
int s[M][M];
int a[N];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a, a+n);
	if(n <= 2) {
		cout << 0;
		return 0;
	}
	if(n == 3) {
		if(a[0]+a[1] > a[2]) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	if(a[n-1] <= 1) {
		if(a[n-1] == 1) {
			int iid = 2, ans = 0;
			for(int i = 0; i < n; i ++) {
				for(int j = 0; j < n; j ++) {
					int po = 0;
					for(int k = i; k <= j; k ++) po += a[k];
					if(po > iid && !s[i][j] && !s[j][i]) {
						s[i][j] = s[j][i] = 1;
						ans ++;
					}
				}
			}
			cout << ans;
		}
		if(a[n-1] == 0) {
			cout << 0;
			return 0;
		}
	}
	return 0;
}