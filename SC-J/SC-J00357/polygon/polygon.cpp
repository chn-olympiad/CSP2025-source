#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int f[5005];
int sum[5005];
int ans;
int maxx;
map<int, int> used;
//bool cmp(int a, int b) {
//	return a>b;
//}
//void dfs(int l, int r, int maxn) {
//	if (r == n) {
//		maxx = 0;
//		if (sum[r]-sum[l-1] > 2*maxn 
//		&& r-l+1 >= 3) {
//			ans++;
//		}
//		return;
//	}
//	for (int i=l; i<=n; i++) {
//		maxx = max(maxn, a[i]);
//		dfs(l, i, maxx);
//	}
//}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}
//	sort(a+1, a+1+n, cmp);
//	dfs(1, 1, a[1]);
	for (int r=n; r>=1; r--) {
		for (int l=1; l<r; l++) {
			for (int x=l+2; x<r; x++) {
				for (int j=x; j<=r; j++)
					maxx = max(maxx, a[j]);
				for (int y=l+1; y<x; y++) {
					maxx = max(maxx, a[y]);
					//if (r==l || r==x || x==y || y==l) continue;
					int cnt = sum[r]-sum[x-1]+sum[y]-sum[l-1];
					//&& r-x+2+y-l<=n
					if (cnt > 2*maxx && r-x+2+y-l >= 3) {
//						if (used[cnt] == 0) {
							maxx = 0;
//							used[cnt]++;
//							cout << r-x+2+y-l<< endl;
//							cout << cnt << " " << used[cnt] << endl; 
//							for (int k=l; k<=y; k++) {
//								cout << k << " ";
//							}
//							for (int k=x; k<=r; k++) {
//								cout << k << " ";
//							}
//							cout << endl << endl;
							ans++;
//						}
					}
				}
			}
		}
	}
	cout << ans%998244353;
	return 0;
}