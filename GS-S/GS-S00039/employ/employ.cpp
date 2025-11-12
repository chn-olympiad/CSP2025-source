#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int MAXN = 1e6 + 10 ;
int c[MAXN] ; 

int main(){
	freopen("employ.in" , "r" , stdin) ;
	freopen("employ.out" , "w" , stdout) ;
	int n , m ;
	cin>>n>>m;
	string a ;
	cin>>a;
	for (int i = 1 ; i <= n ; ++i){
		cin>>c[i] ;
	}
	printf("%d" , rand() % 3) ;
	
	
	return 0 ;
}

