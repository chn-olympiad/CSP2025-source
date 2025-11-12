#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct ren {
	int id;
	int myd;
} b1[N], b2[N], b3[N];
bool cmt (ren x, ren y) {
	return x.myd > y.myd;
}
int T;
int n, a1, a2, a3;
int ans;
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a1 >> a2 >> a3;
			b1[i].id = i;
			b1[i].myd = a1;
			b2[i].id = i;
			b2[i].myd = a2;
			b3[i].id = i;
			b3[i].myd = a3;
		}
		sort (b1 + 1, b1 + n + 1, cmt);
		sort (b2 + 1, b2 + n + 1, cmt);
		sort (b3 + 1, b3 + n + 1, cmt);
		//cout << b1[1].myd << "->b1 " << b2[1].myd << "->b2 " << b3[1].myd << "->b3\n";
		int i = 1, j = 1, k = 1;
		int s1 = 0, s2 = 0, s3 = 0, r = 0;
		int vis[N] = {};
		while (r < n) {
			int l;
			int max1 = max(b1[i].myd, max(b2[j].myd, b3[k].myd));
			int max2 = min(max(b1[i].myd, b2[j].myd), max(b1[i].myd, b3[k].myd));
			int max3 = min(b1[i].myd, min(b2[j].myd, b3[k].myd));
			if (max1 == b1[i].myd && s1 < n / 2 && !vis[b1[i].id]) {
				l = 1;
			}
			else if (max1 == b2[j].myd && s2 < n / 2 && !vis[b2[j].id]){
				l = 2;
			}
			else if (max1 == b3[k].myd && s3 < n / 2 && !vis[b3[k].id]){
				l = 3;
			}
			else if (max2 == b1[i].myd && s1 < n / 2 && !vis[b1[i].id]){
				l = 1;
			}
			else if (max2 == b2[j].myd && s2 < n / 2 && !vis[b2[j].id]){
				l = 2;
			}
			else if (max2 == b3[k].myd && s3 < n / 2 && !vis[b3[k].id]){
				l = 3;
			}
			else if (max3 == b1[i].myd && s1 < n / 2 && !vis[b1[i].id]){
				l = 1;
			}
			else if (max3 == b2[j].myd && s2 < n / 2 && !vis[b2[j].id]){
				l = 2;
			}
			else if (max3 == b3[k].myd && s3 < n / 2 && !vis[b3[k].id]){
				l = 3;
			}
			if (l == 1) {
				ans += b1[i].myd;
				s1++;
				vis[b1[i].id] = 1;
				i++;
				r++;
			}
			if (l == 2) {
				ans += b2[j].myd;
				s2++;
				vis[b2[j].id] = 1;
				j++;
				r++;
			}
			if (l == 3) {
				ans += b3[k].myd;
				s3++;
				vis[b3[k].id] = 1;
				k++;
				r++;
			}
		}
		//cout << r; 
		cout << ans << "\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4  0 0
*/