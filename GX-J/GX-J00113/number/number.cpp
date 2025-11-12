#include<iostream>
#include<algorithm>
using namespace std ;

string s ;
int a[100100] ;

bool cmp(int x , int y ) {
	return x > y ;
}

int main() {
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	cin >> s ;
	int siz = 0 ;
	int len = s.size() ;
	for( int i = 0 ; i < len ; i ++ ) {
		if( s[i] >= '0' && s[i] <= '9' ) {
			siz ++ ;
			a[siz] = s[i] - '0' ;
		}
	}
	sort(a+1,a+siz+1,cmp) ;
	for( int i = 1 ; i <= siz ; i ++ ) {
		cout << a[i] ;
	}
	cout << endl ;
	return 0 ;
}
