#include<bits/stdc++.h>
using namespace std ;
int a[105];
int main(){
	freopen("polygon.in","w",stdin) ;
	freopen("polygon.out","r",stdout) ;
	int n ;
	cin >> n ;
	for(int i = 0;i < n;i++){
		cin >> a[i] ;
	}
	sort(a,a+n) ;
	return 0 ;	
}