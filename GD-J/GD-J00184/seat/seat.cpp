#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[1000005];
int k;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	k = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 0;
	bool f = 1;
	for(int i = 1; i <= n * m; i++){
		if(f == 1){
			y ++;
		}else{
			y --; 
		}
		if(f == 1){
			if(y == n + 1){
				x ++;
				f = 0;
				y = n;
			}
		}else{
			if(y == 0){
				x ++;
				f = 1; 
				y = 1;
			}
		}
		if(a[i] == k){
			cout << x << " " << y;
			return 0;
		}
	}
	return 0;
} 
