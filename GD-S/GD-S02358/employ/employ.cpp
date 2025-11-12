#include<bits/stdc++.h>
using namespace std ;
const int N = 998244353 ; 
int main(){
	freopen("employ.in" , "r",stdin) ; 
	freopen("employ.out" , "w",stdout) ;
	int m,n;
	string s;
	cin>>m >> n ;
	cin>>s ; 
	for(int i = 1 ; i <= m;i++){
		int a ;
		cin >>a ;
	}
	long long ans = 1 ;
	for(int i = 1 ; i<= m ; i++){
		ans=(ans*i)%N ;
	}
	cout <<ans;
	
	
	return 0 ;
}
