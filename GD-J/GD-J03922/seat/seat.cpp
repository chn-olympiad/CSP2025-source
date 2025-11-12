#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int n, m;
int a[1005];

pair<int, int> calc_seat_xy(int x) {
	int row, col;
	
	if (x % n != 0) {
		row = x / n + 1;
	} else {
		row = x / n;
	}
	
	col = x - n * (row - 1);
	if (row % 2 == 0) {
		col = n - col + 1;
	}
	
	return {row, col}; 
}

int main() {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	
	cin >> n >> m;
	
	int score = 1;
	
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		
		if (i == 1) score = a[i];
	}
	
	sort(a + 1, a + n * m + 1, greater<int>());
	
	auto ans = calc_seat_xy(find(a + 1, a + n * m + 1, score) - a);
	
	cout << ans.first << ' ' << ans.second << endl;
	
	return 0;
}
 
