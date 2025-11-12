#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int lu[1000005][5], xian[15][10005], a[10005];
double s[2][1100005]; 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int y = 0;
	cin >> n >> m >> k; 
	for(int i = 1; i <= m; i++) {
		cin >> lu[i][1] >> lu[i][2] >> lu[i][3]; 
		s[0][k] = lu[i][3] / 2 * 1.00;
		y++;
	}
	for(int i = 1; i <= k; i++) {
		cin >> xian[i][1];
		for(int j = 2; j <= n + 1;j++) {
			cin >> xian[i][j];
			s[0][k] = (xian[i][j] + xian[i][1]) / 2 * 1.00;
			s[1][k] = xian[i][1];
			y++;
		} 
	}
	for(int i = 1; i <= m; i++) {
		a[lu[i][1]] = i;
		a[lu[i][2]] = i;
	}
	for(int i = 0; i < y - 2; i++) {
		for(int j = i + 1; j < y - 1; j++) {
			if(s[0][i] > s[0][j]) swap(s[0][i], s[0][j]);
		}
	}
	int ans = 0, c = m;
	for(int i = 0; i < y - 1; i++) {
		if(c == 0) break;
		ans += s[0][i] * 2 - s[1][i];
		c--;
	
	}
	printf("%d", ans);
	return 0;
}
