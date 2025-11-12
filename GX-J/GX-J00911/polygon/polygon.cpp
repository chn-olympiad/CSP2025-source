#include<bits/stdc++.h>
using namespace std ;
int n , a[5005] ;
int main(){

	cin >> n ;
	for (int i = 1 ; i <= n ; i++){
	cin >> a[i] ;
 	if (i == 1){
		if (a[i] % 2 == 0){
			cout << a[i + 2] * a[i + 2] ;
		}
		else{
			cout << a[i + 1] * a[i + 2] ;
			}
		}
		else {
			break ;
		}
	}
	return 0 ;
}
