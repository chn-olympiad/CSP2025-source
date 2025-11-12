#include<bits/stdc++.h>
using namespace std ;
int n , m ,a[105] , cnt = 0 , b;
int main(){

	cin >> n >> m ;
	for (int i = 1 ; i <= n * m ; i++){
		cin >> a[i] ;
		if (i == 1){
		b = a[i] ;
		}
		if (a[i + 1] > b){
			cnt++;
		}
		if (i == n * m ){
			if (cnt > 1){
				if (cnt % 2 != 0){
				if (cnt % 2 != 0){
				cout << cnt / 2 + 1  << " " << cnt % 2;
				}
					else{
					cout << cnt / 2 + 1 << " " << m - cnt % 2 ;
					}
				}
				else if (cnt % 2 == 0){
				if (cnt % 2 != 0){
				cout << cnt / 2 << " " << "4" ;
				}
					else {
					cout << cnt / 2 << " " << "1" ;
					}
				}
			}
			else {
			cout << "1" << " " << cnt ;
			}
		}

	}

	return 0 ;
}
