#include<bits/stdc++.h>

using namespace std ;

char s[1000005] ;

int cnt[10] ;

signed main(){
	
	freopen("number.in","r",stdin) ; 
	freopen("number.out","w",stdout) ; 
	scanf("%s" , s ) ; 
	
	int len = strlen(s) ; 
	
	for(int i = 0 ; i < len ; i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			cnt[s[i]-'0'] += s[i] ;
		}
	}
	
	for(int i = 9 ; i >= 0 ; i --){
		for(int j  = 1 ; j <= cnt[i] ; j ++){
			printf("%d",i) ; 
		}
	}
	
	return 0 ; 
}
/*
99998888887777766666655555544444433332111000000000
99998888887777766666655555544444433332111000000000

*/

