//GZ-S00352 贵阳市白云区华师一学校 秦子懿 
#include <bits/stdc++.h>
using namespace std ;
int n , m;
int c[510] ;
int cc[510] ;
string s ;
vector<int> v ;
bool f[510] = {0} ;
map<vector<int> , bool> mp ;
long long cnt ;
bool check(){
	for(int i = 1 ; i <= n ; i ++){
		cc[i] = c[v[i - 1]] ;
	}
	int now = 0 ;
	for(int i = 1 ; i <= n ; i ++){
		if(now >= cc[i] || s[i - 1] == '0') now ++ ;
	}
	return (n - now) >= m ; 
}
void aa(){
	if(v.size() == n){
		if(!mp[v]){
			int f =check() ;
			cnt += f ;
			cnt %= 998244353 ;
			mp[v] = 1 ;
		}
		
		return ;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(f[i]) continue ;
		v.push_back(i) ;
		f[i] = 1 ;
		aa() ;
		v.pop_back() ;
		f[i] = 0 ;
	}
}
int main(){
	freopen("employ.in" , "r" , stdin) ;
	freopen("employ.out" , "w" , stdout) ;
	scanf("%d%d" , &n , &m) ;
	cin >> s ;
	for(int i = 1; i <= n ; i ++) scanf("%d" , &c[i]) ;
	bool f = 1 ;
	for(int i = 1 ; i <= n ; i ++){
		if(s[i - 1] == '0'){
			f =0 ;
			break ;
		}
	}
	if(f){
		cnt = 1 ;
		for(int i = 1 ; i <= n ; i ++){
			cnt *= i ;
			cnt %= 998244353 ;
		}
		printf("%lld" , cnt) ;
		return 0 ;
	}
	aa() ;
	printf("%lld" , cnt) ;
	return 0 ;
}
