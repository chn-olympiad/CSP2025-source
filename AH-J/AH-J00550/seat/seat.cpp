#include <bits/stdc++.h>
using namespace std;
int a[1005];
int s[105][105];
int tgt;
bool cmp(int a,int b) {
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	tgt = a[1];
	sort (a + 1, a + n * m + 1, cmp);
	int x = 0;
	for (int i = 1; i <= n; i ++) {
		
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j ++) {
				s[i][j] = a[x + 1];
				x ++;
			}
		}
		else {
			for (int j = m; j >= 1; j --) {
				s[i][j] = a[x + 1];
				x ++;
			}
		}
	}
	int dx,dy;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (s[i][j] == tgt) {
				dx = i;
				dy = j;
			}
		}
	}
	cout << dx << " " << dy;
	return 0;
}
