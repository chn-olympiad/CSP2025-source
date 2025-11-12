//GZ-S00352 贵阳市白云区华师一学校 秦子懿 
#include <bits/stdc++.h>
using namespace std ;
int T ;
struct N{
	int id ;
	int a , b , c ;
	int ch ;
} p[100000 + 10] ;
int n ;
vector<N> clr ;
vector<N> cb1 , cb2 , cb3 ; 
long long sum ;
bool c1(N A , N B){
	return A.ch > B.ch ; 
}
bool c2(N A , N B){
	return A.b > B.b ;
}
bool c3(N A , N B){
	return A.c > B.c ;
}
int main(){
	freopen("club.in" , "r" , stdin) ;
	freopen("club.out" , "w" , stdout) ;
	scanf("%d" , &T) ;
	while(T --){
		sum = 0 ;
		cb1 = clr ;
		cb2 = clr ;
		cb3 = clr ;
		scanf("%d" , &n) ;
		for(int i = 1 ; i <= n ; i ++){
			scanf("%d%d%d" , &p[i].a , &p[i].b , &p[i].c) ;
			p[i].id = i ;
		}
		for(int i = 1 ; i <= n ; i ++){
			if(p[i].a > p[i].b){
				if(p[i].a > p[i].c) cb1.push_back(p[i]) ;
				else cb3.push_back(p[i]) ;
			}else{
				if(p[i].b > p[i].c) cb2.push_back(p[i]) ;
				else cb3.push_back(p[i]) ; 
			}
		}
		if(cb1.size() > n / 2){
			for(int i = 0 ; i < cb1.size() ; i ++){
				cb1[i].ch = cb1[i].a - max(cb1[i].b , cb1[i].c) ;
			}
			sort(cb1.begin() , cb1.end() , c1) ;
			while(cb1.size() > n / 2){
				N x = cb1[cb1.size() - 1] ;
				cb1.pop_back() ;
				x.a = 0 ;
				if(x.b > x.c) cb2.push_back(x) ;
				else cb3.push_back(x) ;
			}
		}
		if(cb2.size() > n / 2){
			for(int i = 0 ; i < cb2.size() ; i ++){
				cb2[i].ch = cb2[i].b - max(cb2[i].a , cb2[i].c) ;
			}
			sort(cb2.begin() , cb2.end() , c1) ;
			while(cb2.size() > n / 2){
				N x = cb2[cb2.size() - 1] ;
				cb2.pop_back() ;
				x.b = 0 ;
				if(x.a > x.c) cb1.push_back(x) ;
				else cb3.push_back(x) ;
			}
		}
		if(cb3.size() > n / 2){
			for(int i = 0 ; i < cb3.size() ; i ++){
				cb3[i].ch = cb3[i].c - max(cb3[i].b , cb3[i].a) ;
			}
			sort(cb3.begin() , cb3.end() , c1) ;
			while(cb3.size() > n / 2){
				N x = cb3[cb3.size() - 1] ;
				cb3.pop_back() ;
				x.c = 0 ;
				if(x.a > x.b) cb1.push_back(x) ;
				else cb2.push_back(x) ;
			}
		}
		for(int i = 0 ; i < cb1.size() ; i ++) sum += cb1[i].a ;
		for(int i = 0 ; i < cb2.size() ; i ++) sum += cb2[i].b ;
		for(int i = 0 ; i < cb3.size() ; i ++) sum += cb3[i].c ;
		printf("%lld\n" , sum) ;
	}
	
	return 0 ;
}
