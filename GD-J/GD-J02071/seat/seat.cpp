#include <bits/stdc++.h>
using namespace std;

int n, m, a[111];

bool cmp (int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int t = a[1], p = 0;
	sort (a + 1, a + n * m + 1, cmp);
	for (int j = 1; j <= m; j++){
		if (j % 2){
			for (int i = 1; i <= n; i++){
				p++;
				if (a[p] == t){
					cout << i << " " << j;
					return 0;
				}
				
			}
		}
		else {
			for (int i = n; i >= 1; i--){
				p++;
				if (a[p] == t){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
