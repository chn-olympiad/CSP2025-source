#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 15;
int n, a[N], m, k;
int b[N][N];
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++){
		scanf("%d", &a[i]);
	}
	k = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	int x = 1, y = 1;
	for (int i = 1; i <= n * m; i++){
		if (a[i] == k){
			printf("%d %d", y, x);
			break;
		}
		if (y % 2 == 1){
			x++;
			if (x > n){
				x--;
				y++;
			}
		}else{
			x--;
			if (x < 1){
				x++;
				y++;
			}
		}
	}
	return 0;
}
