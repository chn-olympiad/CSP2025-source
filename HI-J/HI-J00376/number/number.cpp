#include<bits/stdc++.h>

using namespace std ;

const int N = 1e6 + 6 ;

string n ;
int a[N] = {} ;
int num = 0 ;

int main(){
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	
	cin >> n ;
	int len = n.size() ;
	for(int i = 0 ; i < len ; i++){
		if(n[i] <='9' && n[i] >= '0'){
			a[num] = n[i] - '0' ;
			num ++ ;
		}
	}
	sort(a,a+num) ;
	for(int i = num-1 ; i >= 0 ; i-- ){
		cout << a[i] ;
	}
	
	return 0 ;
}
