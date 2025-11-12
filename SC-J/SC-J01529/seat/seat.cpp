#include<bits/stdc++.h>
using namespace std;
const int N = 1010 , M = 20;
int a[N] , b[M][M];
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m , p = 0;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	p = a[1];
	sort(a + 1 , a + n * m + 1 , cmp);
	int x = 1 , y = 1 , k = 0;
	bool cnt = 1; 
	b[x][y] = a[++k];
	while(x * y <= n * m){
		if(cnt == 0){
			x--;
		} else {
			x++;
		}
		if(x == n + 1){
			x = n;
			y++;
			cnt = 0;
		} else if(x == 0){
			x = 1;
			y++;
			cnt = 1;
		} 
		b[x][y] = a[++k];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(b[i][j] == p){
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
}