#include <bits/stdc++.h>

using namespace std;

const int N = 17;
int a[N * N], seat[N][N];
int n, m;

int main() {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int score = a[1];
	
	sort(a + 1, a + n * m + 1, greater<int>() );
	int h = 1, l = 1;
	for(int i = 1; i <= n * m; i++) {
		if(h == n + 1) {
			h = n;
			l++;
		}
		if(h == 0) {
			h = 1;
			l++;
		}
		if(l % 2 == 0) {
			seat[h][l] = a[i];
			h--;
		} else {
			seat[h][l] = a[i];
			h++;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(seat[i][j] == score) {
				cout << j << ' ' << i;
				return 0; 
			}
		}
	}

	return 0; 
} 
