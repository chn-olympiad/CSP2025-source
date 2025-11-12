#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b[15][15];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int scr = a[1];
	sort(a + 1, a + n * m + 1);
	int num = n * m;
	for (int c = 1; c <= m; c++){
		if (c % 2 == 1){
			for (int r = 1; r <= n; r++){
				if (a[num] == scr){
					cout << c << " " << r;
					return 0;
				}
				num--;
			}
		}
		else{
			for (int r = n; r >= 1; r--){
				if (a[num] == scr){
					cout << c << " " << r;
					return 0;
				}
				num--;
			}
		}
	}
	return 0;
}
