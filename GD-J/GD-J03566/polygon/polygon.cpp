#include <iostream>
using namespace std ;
int Data[4] ;
int main () {
	
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	int n ;
	cin >> n ;
	if (n < 3) {
		cout << 0 ;
		return 0 ;
	}
	cin >> Data[1] >> Data[2] >> Data[3] ;
	if (Data[1]+Data[2] > Data[3] &&
	 Data[1] + Data[3] >= Data[2] &&
	 Data[2] + Data[3] >= Data[1]) {
	 	cout << 1 ;
	 }
	 else 
	 	cout << 0 ;
}
