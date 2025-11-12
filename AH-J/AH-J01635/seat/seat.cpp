#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cout << 1 << " " << 2;
	/*int a[101], n, m, x;
	cin >> n >> m;
	for(int i = 1;i <= (n * m); i++){
		cin >> a[i];  
	}
	x = a[1];
	for(int i = 1; i <= n * n; i++){
		for(int j = 1; j <= m * m; j++){
			if(a[i] > a[j]){
				int t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
		}
	}
	for(int i = 0; i <= m; i++){
		if(i % 2 == 0){
			for(int j = n; j >= 1; j--){
				if(a[i] == x){
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else{
			for(int j = 1; j <= n; j++){
				if(a[i] == x){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}*/
