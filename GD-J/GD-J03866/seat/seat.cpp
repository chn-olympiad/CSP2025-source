#include <bits/stdc++.h>

using namespace std;

int const maxn = 100 + 10;
int seat[maxn][maxn];
int a[maxn * maxn];
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m , r , rs;
	cin >> n >> m;
	for (int i = 1 ; i <= n * m ; i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1 , a + n * m + 1);
	for (int i = 1 ; i < n * m ; i++){
		if (a[i] == r){
			rs = n * m - i + 1;
			break;
		}
	} 
	for (int i = 1 ; i <= n ; i++){
		seat[i][1] = i;
		seat[i][2] = 2 * n + 1 - i;
	}
	for (int i = 1 ; i <= n ; i++){
		for (int j = 3 ; j <= m ; j++){
			seat[i][j] = seat[i][j - 2] + 2 * n;
		}
	}
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1 ; j <= m ; j++){
			if (seat[i][j] == rs){
				cout << j << ' ' << i << endl;
				return 0; 
			}
		}
	}
	return 0;
}
