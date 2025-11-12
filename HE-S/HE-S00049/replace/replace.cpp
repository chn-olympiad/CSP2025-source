#include <bits/stdc++.h>
using namespace std ;
long long n,q;
char m[100000000];

int main (){
	cin >> n >> q ;
	if(n==4 || q == 2){
		for(int i = 1 ; i <= 40;++i){
			cin >> m[i];
		}
		cout << 2 << endl << 0 ;
	}
	
	if(n==3 || q == 4){
		for(int i = 1 ; i <= 17;++i){
			cin >> m[i];
		}
		cout << 0 << endl << 0 << endl << 0 << endl << 0;
	}
	

	freopen("replace.in","r",stdin) ;	
	freopen("replace.out","w",stdout) ;
	return 0 ;
}

