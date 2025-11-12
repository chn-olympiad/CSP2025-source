#include<bits/stdc++.h>
using namespace std;
int a[1005]; 
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r;
	cin >> n >> m;
	for(int i = 0; i < n * m; i++){
			cin >> a[i];
			if(i == 0){
				r = a[i];
			}
	}
	for(int i = 0; i < n * m + 1; i++){
		for(int j = 0; j < n * m + 1; j++){
		 	if(a[i + 1] > a[i]){
		 		int ch = a[i];
		 		a[i] = a[i + 1];
		 		a[i + 1] = ch;
		 	}	
		}
	}
	for(int i = 0; i < n * m; i++){
		if(r == a[i] && i / m % 2 == 0){
			cout << i / m + 1 << ' ' << i % m + 1;
			return 0;
		} else if(r == a[i] && i / m % 2 == 1){
			cout << m - i % m << ' ' << i / m + 1;
			return 0;
		}
	}
	return 0;
} 
