#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, m;
	int a, b, c;
	int cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> m[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(a[i] + b[j] > c[k] ){
					cnt++;
				}
				if(a[j] + b[i] > c[k] ){
					cnt++;
				}
				if(a[k] + b[k] > c[j] ){
					cnt++;
				}
				if(a[i] + b[k] > c[j] ){
					cnt++;
				}
				if(a[j] + b[k] > c[i] ){
					cnt++;
				}
				if(a[k] + b[j] > c[i] ){
					cnt++;
				}
			}
		}
	}
	cout << cnt%998 << cnt%244 << cnt%353; 
	return 0;
} 
