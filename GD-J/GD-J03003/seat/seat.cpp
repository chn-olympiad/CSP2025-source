#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int a[MAXN];
int ans[MAXN][MAXN];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, k;//k mean a1
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >> a[i];
		if (i == 1) k = a[i];
	}
	sort(a+1, a+n*m+1, cmp);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int x = (i%2==1) ? j:m-j+1;
			int y = i;
			//cout << x << " " << y << endl;
			ans[x][y] = a[i*n+j-n];
		}
	}
	int x = 0, y = 0;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			//cout << ans[i][j] << " ";
			if (ans[i][j] == k){
				x = i;
				y = j;
			}
		}
		//cout << endl;
	}
	cout << y << " " << x; 
	return 0;
} 
