#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue<array<int, 3>, vector<array<int, 3> >, greater<array<int, 3> > > p[3];

array<int, 3> a[100009][3];

void sovel() {
	int ans = 0;
	while(p[0].size()) p[0].pop();
	while(p[1].size()) p[1].pop();
	while(p[2].size()) p[2].pop();
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i][0][0] >> a[i][1][0] >> a[i][2][0];
		a[i][0][2] = 0;
		a[i][1][2] = 1;
		a[i][2][2] = 2;
		a[i][0][1] = -p[0].size();
		a[i][1][1] = -p[1].size();
		a[i][2][1] = -p[2].size();
		sort(a[i], a[i] + 3);
		reverse(a[i], a[i] + 3);
		for(int j = 0; j < 3; j++) {
			if(p[a[i][j][2]].size() != n / 2) {
				p[a[i][j][2]].push({a[i][j][0] - a[i][j + 1][0], i, j});
				ans += a[i][j][0];
				break;
			}
			int x = p[a[i][j][2]].top()[0];
			int y = p[a[i][j][2]].top()[1];
			int z = p[a[i][j][2]].top()[2];
			if(a[i][j][0] - x > a[i][j + 1][0]) {
				ans += a[i][j][0];
				ans -= x;
				p[a[y][z + 1][2]].push({a[y][z + 1][0] - a[y][z + 2][0], y, z + 1});
				p[a[i][j][2]].pop();
				p[a[i][j][2]].push({a[i][j][0] - a[i][j + 1][0], i, j});
				break;
			}
		} 
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin >> T;
	while(T--) {
		sovel();
	}
	
	return 0; 
}
