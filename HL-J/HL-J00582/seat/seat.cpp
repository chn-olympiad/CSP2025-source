#include<bits/stdc++.h>
using namespace std ;
int a[105],x,y,b[105][105];
int cmp(int x,int y){
	return x > y ;
}
int main(){
	freopen("seat.in","w",stdin) ;
	freopen("seat.out","r",stdout) ;
	int n , m ;
	cin >> n >> m ;
	for(int i = 0;i < n*m;i++){
		cin >> a[i] ;
	}
	int t = a[0] ;
    sort(a,a+n*m,cmp) ;
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			if(i%2!=0&&j==0){
				sort(a+i*n+j,a+i*n+j+n) ;
			}
			b[i][j] = a[i*n+j] ;
			if(b[i][j]==t){
				x = i ;
				y = j ;
				cout << x+1 << " " << y+1 ;
				return 0 ;
			}
		}
	}
	return 0 ;	
}
