#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[105], k;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
		k = a[1];
	}
	for(int i = 1; i <= n * m; i++){
		for(int i = 2; i <= n * m; i++){
			if(a[i] >= a[i - 1]){
				swap(a[i], a[i - 1]);
			}
		}
	}
	int r[105], c[105];
	for(int i = 1; i <= n * m; i++){
		c[i] = i / n + 1;
		if(c[i] % 2 != 0){
			r[i] = c[i] + i % n;
		}else{
			r[i] = n + 1 - (i % n);
		} 
		if(a[i] == k){
			cout << r[i] << " " << c[i];
			return 0;
		}
	}
} 
