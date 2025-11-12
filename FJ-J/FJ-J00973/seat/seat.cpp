#include <bits/stdc++.h>
using namespace std;
int a[105];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int j = 1; j <= n * m; j++){
		cin >> a[j];
	}
	int b = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int i = 1;
	for(int j = 1; j <= n * m; j++){
		if(a[j] == b){
			break;
		}else{
			i++;
		}
	}
	int x = 1, y = 1;
	for(int j = 1; j < i; j++){
		if(x % 2 != 0){
			y++;
		}else{
			y--;
		}
		if(y == n + 1){
			y = n;
			x++;
		}else if(y == 0){
			y = 1;
			x++;
		}
	}
	cout << x << " " << y;
	return 0;
}
