#include <bits/stdc++.h>
using namespace std;
int a[200];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int s = a[1];
	sort(a + 1, a + n * m + 1);
	int x = 1, y = 1;
	for (int i = n * m; i >= 1; i--){
		if (s == a[i]){
			break;
		}
		if (x % 2 == 1){
			y++;
			if (y == n + 1){
				y = n;
				x++;
			}
		}
		else{
			y--;
			if (y == 0){
				y = 1;
				x++;
			}
		}
	}
	cout << x << " " << y << '\n';
	return 0;
} 
