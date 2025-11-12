#include <bits/stdc++.h>
using namespace std ;
const int Maxn = 1e6 + 10 ;
char S[Maxn] ;
char Data[Maxn] ;
char t[1005] ;
bool cmp(const char &a , const char &b) {
	return a > b ;
}
int main () {
	
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	scanf(" %s" , S ) ;
//	for ( int i = 0 ; i < strlen(S) ; i++ ) {
//		if (S[i] >= '0' && S[i] <= '9') {
//			Data[k++] = S[i] ;
//		}
//	}
	sort(S , S+strlen(S) ) ;
	sscanf(S ," %[0-9]" , Data) ;
	sort(Data , Data+strlen(Data) , cmp ) ;
	printf (Data) ;	
	return 0 ;
}
