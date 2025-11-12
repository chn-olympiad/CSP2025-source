#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, c = 1, r = 1, xiaoR, a[105];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m >> xiaoR;
	a[1] = xiaoR;
	for (int i = 2; i <= n * m; i++){
		cin >> a[i];
	}
	sort(a + 1, a + (n * m) + 1, cmp);
	
	int cnt = 1;
	for (int i = 1; i <= m; i++){
		if (i % 2 == 1){
			for (int j = 1; j <= n; j++){
				if (a[cnt] == xiaoR){
					c = i;
					r = j;
				}
				cnt++;
			}
		}
		else{
			for (int j = n; j >= 1; j--){
				if (a[cnt] == xiaoR){
					c = i;
					r = j;
				}
				cnt++;
			}
		}
	}
	cout << c << " " << r;
	
	return 0;
} 
