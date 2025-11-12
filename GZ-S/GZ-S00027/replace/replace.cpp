// GZ-S00027 贵阳中天中学 何棂宸
#include <bits/stdc++.h>
using namespace std ;

const int N = 2e5+5 ;
int n , q , pbt1[N] , pbt2[N] , pbs1[N] , pbs2[N];
string s1[N] , s2[N] , t1[N] , t2[N] ;

int main(){
	freopen("replace.in","r",stdin) ;
	freopen("replace.out","w",stdout) ;
	cin >> n >> q ;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> s1[i] >> s2[i] ;
	}	
	for ( int i = 1 ; i <= q ; i++ ){
		cin >> t1[i] >> t2[i] ;
	}
	for ( int i = 1 ; i <= n ; i++ ){
		for ( int j =  0 ; j < s1[i].size() ; j++ ){
			if ( s1[i][j] == 'b' ) pbs1[i] = j ;
		}
		for ( int j =  0 ; j < s2[i].size() ; j++ ){
			if ( s2[i][j] == 'b' ) pbs2[i] = j ;
		}
	}
	for ( int i = 1 ; i <= q ;i ++){
		long long ans = 0 ;
		for ( int j =  0 ; j < t1[i].size() ; j++ ){
			if ( t1[i][j] == 'b' ) pbt1[i] = j ;
		}
		for ( int j =  0 ; j < t2[i].size() ; j++ ){
			if ( t2[i][j] == 'b' ) pbt2[i] = j ;
		}
		for ( int j = 1 ; j <= n ; j++ ){
			long long a = t1[i].size()-pbt1[i] , b = s1[j].size()-pbs1[j] ;
			long long c = t2[i].size()-pbt2[i] , d = s2[j].size()-pbs2[j] ;
			if ( (pbt1[i]-pbs1[j]+pbs2[j] == pbt2[i]) && (a-b+d==c) ) ans++ ;
//			cout << pbt1[i]<<" " <<pbs1[j]<<" " <<pbs2[j]<<" " <<pbt2[i]<< endl ;
//			cout << a<<" " <<b<<" " <<d<<" " <<c<<endl; 
		}
		cout << ans << endl ;
	}
	return 0 ;
}
/*
3 1
aaba abaaaa
aaaaba aba
aaaab abaaa
aaaabaaaa
abaaaaaaa
*/
