#include<bits/stdc++.h>
using namespace std ;

int n , q ; 
struct node {
	char s1[10005] , s2[10005] ;
}v[10005];

int ans ; 

bool find(string s , string k){
	for(int i = 1 ;i <= n ; i ++){
		if(v[i].s1 == s && v[i].s2 == k){
			return true ;
		}
	}
	return false ;
}

signed main(){
	
	freopen("replace.in","r",stdin) ;
	freopen("replace.out","w",stdout) ;
	
	scanf("%d%d" , &n , &q) ;
	for(int i = 1 ; i <= n ; i ++){
		scanf("%s%s" , v[i].s1 , v[i].s2) ;
	}
	while(q --){
		string t1,t2 ;
		cin >> t1 >> t2 ;
		int len = max(t1.size() , t2.size()) ;  
		for(int i = 0 ; i < len ; i ++){
			for(int j = i ; j < len ; j ++){
				if( find(t1.substr(i , j - i + 1),t2.substr(i , j - i )) ){
					ans ++ ; 
				}
			}
		}
		cout << ans << endl ; 
	}
	return 0 ;
}
