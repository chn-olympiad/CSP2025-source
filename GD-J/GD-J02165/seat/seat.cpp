#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 101, M = 11;
int n, m, a[N], temp;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[(i - 1) * n + j];
			if(i == 1 && j == 1){
				temp = a[(i - 1) * n + j];
			}
		}
	}
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1, x = 1, y = 1; i <= n * m; i++){
		y = (i - 1) / n + 1;
		if(y % 2){
			x = i % n;
		}else{
			x = n + 1 - (i % n == 0 ? n : i % n);
		}
		if(!x) x = n;
		if(a[i] == temp){
			cout << y << ' ' << x;
			return 0;
		}
	}
	return 0;
}
