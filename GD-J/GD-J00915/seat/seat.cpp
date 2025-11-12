#include<bits/stdc++.h>
using namespace std ;

int n , m ;
int b[105] ; 

bool cmp(int x, int y){
	return x > y ; 
}

void dfs(int x , int y , int id , int cnt){
	if(id == cnt){
		cout << y << " " << x << endl ;
		return ;
	}
	//cout << y << " " << x << endl ; 
	if( y%2 == 1 && x < n ){
		dfs(x + 1  , y  , id , cnt + 1) ; 
	}else if( y%2 == 0 && x > 1 ){
		dfs(x - 1  , y  , id , cnt + 1) ; 
	}else if(x == n && y%2 == 1){
		dfs(x , y + 1  , id , cnt + 1) ;
	}else if(x == 1 && y%2 == 0){
		dfs(x , y + 1  , id , cnt + 1) ;
	}
}

int cnt ;

signed main(){
	
	freopen("seat.in","r",stdin) ; 
	freopen("seat.out","w",stdout) ; 
	
	scanf("%d%d" , &n , &m) ;
	for(int i = 1 ; i <= n * m ; i ++){
		scanf("%d" , &b[i]) ;
	}
	int k = b[1] ;
	int jj = 0  ;
	sort(b + 1 , b + n * m + 1  ,cmp) ;
	for(int i = 1 ; i <= n * m ; i ++){
		if(b[i] == k){
			jj = i ; 
		}
		//cout << b[i] ;
	} 
	dfs(1 , 1 , jj , 1 ) ;  
	
	
	return 0 ; 
}

/*
2 2
98 97 99 100
3 3
94 95 96 97 98 99 100 93 92
*/
