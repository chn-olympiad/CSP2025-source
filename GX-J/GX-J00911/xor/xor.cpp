#include<bits/stdc++.h>
using namespace std ;
int n , k , a[500005];
int main(){

	cin >> n >> k ;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
		if (k >= 1){
			cout << "2" ;
			break ;
		}
		if (k == 0){
			cout << "1" ;
			break ;
		}
	}
	return 0 ;
}
