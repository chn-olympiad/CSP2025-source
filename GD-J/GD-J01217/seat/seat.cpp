#include <bits/stdc++.h>
using namespace std;
const int N = 15, M = 15;
int n, m, a[N*M], L, s, mp[N][M], it;
bool cmp(int x, int y) {
	return x>y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	L = n*m;
	for(int i=1; i<=L; i++) cin >> a[i];
	s = a[1];
	sort(a+1, a+L+1, cmp);
	for(int i=1; i<=m; i++) {
		if(i%2==1) { // 从上往下填 
			for(int j=1; j<=n; j++) mp[j][i] = a[++it];
		} else { // 从下往上填 
			for(int j=n; j>=1; j--) mp[j][i] = a[++it];
		}
	}
	for(int c=1; c<=m; c++) 
		for(int r=1; r<=n; r++)
			if(mp[r][c]==s) {cout << c << " " << r; break;}
	return 0;
} // 9:01 ok
