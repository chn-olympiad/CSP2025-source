#include<bits/stdc++.h>
using namespace std ;
int a[105] ; 
bool cmp(int x , int y){
	return x > y ; 
}
int main(){
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ; 
	int n , m ;
	cin >> n >> m ; 
	for(int i = 1 ; i <= n*m ; i++)cin >> a[i] ;
	int x = a[1] ; 
	sort(a+1,a+1+n*m,cmp) ; 
	int pos =  0 ; 
	for(int i = 1 ; i <= n*m ;i++){
		if(a[i] == x){
			pos = i ; 
			break ; 
		}
	}
	if(pos <= n){
		cout << 1 << " " << pos ; 
	}
	else{
		int c = (pos-1)/n + 1 ; 
		if(c%2 == 0){
			int r = n-(pos-((c-1)*n)-1) ; 
			cout << c << " " << r ;
		}
		else{
			int r = pos - (c-1)*n ; 
			cout << c << " " << r ; 
		}
	}
	return 0 ; 
}
