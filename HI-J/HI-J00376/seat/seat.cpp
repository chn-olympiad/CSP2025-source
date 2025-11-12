#include<bits/stdc++.h>

using namespace std ;

int n , m ;
int a[1000] = {} ;
int x ;

int main(){
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	
	cin >> n >> m ;
	int num = n*m ;
	for(int i = 1 ; i <= num ; i++){
		cin >> a[i] ;
	}
	x = a[1] ;
	sort(a+1,a+num+1) ;
	for(int i = 1 ; i <= m ; i++) {
		for(int j = 1 ; j <= n ; j++ ){
			if(a[num] == x){
				cout << i << " "  ;
				if(i%2 == 0){
					cout << n-j+1 ;
				}else{
					cout << j ;
				}
				return 0 ;
			}
			
			num-- ;
		}
		
	}
	
	return 0 ;
}
