#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N=105 ;
int a[N] ;

bool cmp(int c,int d){
	return c>d ; 
}

int main(){
    freopen("seat.in", "r", stdin) ;
    freopen("seat.out", "w", stdout) ;
	int n,m ;
	cin >> n >> m ;
	for (int i=1 ; i<=n*m ; i++){
		cin >> a[i] ;
	}
	int ming=a[1],lie=1,hang=1,cnt=1 ;
	sort(a+1,a+(n*m)+1,cmp) ;
	for (int i=1 ; i<=n*m ; i++){
		if (a[i]==ming) break ;
		else{
			hang+=cnt ;
			if (hang<1) lie++,hang=1,cnt=1 ;
			if (hang>n) lie++,hang=n,cnt=-1 ;
		}
	}
	cout << lie << " " << hang ;
	return 0 ;
}
