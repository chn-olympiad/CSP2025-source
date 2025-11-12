# include<bits/stdc++.h>
# define N 15
using namespace std;
int n, m, a[N][N];
int x, y, cnt, cur;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0) -> ios :: sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++) {
			cin >> a[i][j];
			if(a[i][j] > a[1][1])
				cnt ++;
		}
	x = 1, y = 1, cur = 1;
	while(cnt --) {
		if((x == n && cur == 1) || (x == 1 && cur == - 1))
			y += 1, cur = - cur;
		else
			x += cur;
	}
	cout << y << " " << x << "\n";
	return 0;
}