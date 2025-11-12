#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout) ;
	int n ;
	int m ;
	cin >> n >> m ;
	int a1[n*m] ;
	int a2 = 0 ;
	cin >> a1[0] ;
	for(int i = 1 ;i<n*m;i++){
		cin >> a1[i] ;
		if(a1[i]>a1[0]){
			a2 = a2+1 ;
		}
	}
	//cout << a2+1 <<endl;
	int y = a2/n+1 ;
	a2 = a2+1 ;
	int x = a2-(y-1)*n ;
	//if(a2%n==0){
	//	x = n ;
	//}
	cout << y << " " << x ;
	return 0 ;
}

