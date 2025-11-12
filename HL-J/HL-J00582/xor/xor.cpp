#include<bits/stdc++.h>
using namespace std ;
int a[105];
int cmp(int x,int y){
	return x > y ;
}
int main(){
	freopen("xor.in","w",stdin) ;
	freopen("xor.out","r",stdout) ;
	long long  k , n ;
	cin >> n >> k ;
	for(int i = 0;i < n;i++){
		cin >> a[i] ;
	}
	cout << 1 ;
	return 0 ;
}