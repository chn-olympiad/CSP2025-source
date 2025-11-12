#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std ;
const int N = 1e5 + 10 ;
int  n ;
bool flag_A , flag_B ;
struct node1{
int a,b,c;
}s[N];
bool cmp1(node1 x , node1 y){
	return x.a < y.a ;
}
bool cmp2(node1 x , node1 y){
	return x.c > y.c ;
}
int main(){
	ifstream cin ("club.in" ) ;
	ofstream cout("club.out") ;
	int t ;
	cin >> t ;
	while(t--){
		cin >> n ;
		flag_A = true ;
		flag_B = true ;
		for(int i = 0 ; i < n ; i++){
			cin >> s[i].a >> s[i].b >> s[i].c ;
			// 判断是否有性质A/B
			if(flag_B&&!s[i].c==0){
				flag_A = false ;
				flag_B = false ;
			}
			if(flag_A&&!s[i].b==0){
				flag_A = false ;
			}
		}
		// 如果为性质A
		if(flag_A){
			sort(s,s+n,cmp1) ;
			int ans = 0 ;
			for(int i = n / 2 ; i < n ; i++){
				ans += s[i].a ;
			}
			cout << ans << endl ;
			continue ;
		}
		// 如果为性质B
		if(flag_B){
			for(int i = 0 ; i < n ; i++){
				s[i].c = s[i].a + s[i].b;
			}
			sort(s,s+n,cmp2) ;
			int a_n=0 , b_n=0 ,ans=0;
			for(int i = 0 ; i < n / 2 ; i++){
				if(s[i].a > s[i].b){
					b_n++;
					ans += s[i].a;
				}else{
					a_n++;
					ans += s[i].b ;
				}
			}
			for(int i = n / 2 ; i < n ; i++){
				if(s[i].a > s[i].b){
					if(a_n){
						a_n--;
						ans+=s[i].a;
					}else{
						b_n--;
						ans+=s[i].b;
					}
				}else{
					if(b_n){
						b_n--;
						ans+=s[i].b;
					}else{
						a_n--;
						ans+=s[i].a;
					}
				}
			}
			cout << ans << endl ;
			continue ;
		}
	}
	return 0 ;
}