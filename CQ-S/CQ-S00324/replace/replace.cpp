#include <bits/stdc++.h>
//#define int long long
#define lowbit(x) ((x) & -(x))
#define PII pair < int , int >
#define x first
#define y second
using namespace std ;
const int N = 2e5 + 5 , M = 5e6 + 5 ; 
int n , q ; 
string s[N][2] ; 
map < string , string > mp ; 
signed main(){
	freopen("replace.in" , "r" , stdin) ;
	freopen("replace.out" , "w" , stdout) ;
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n >> q ; 
	for(int i = 1 ; i <= n ; i++) cin >> s[i][0] >> s[i][1] ; 
	while(q--){
		string t1 , t2 ; cin >> t1 >> t2 ; 
		int len = t1.size() , l = 0 , r = len - 1 , ans = 0 ; 
		for( ; l < len && t1[l] == t2[l] ; l++) ; 
		l-- ; 
		for( ; ~r && t1[r] == t2[r] ; r--) ; 
		r++ ; 
		if(l > r) l = r = len / 2 ; 
//		cout << l << " " << r << "\n" ; 
		if(len <= 2e3){
			for(int i = 1 ; i <= n ; i++){
				int lle = s[i][0].size() , flag = 1 ; 
				vector < int > a , b ; 
				for(int j = 0 ; j + lle <= len ; j++){
//					cout << j << "*" << s[i][0] << " " << s[i][1] << "\n" ; 
					flag = j + 1 ; 
					for(int k = 0 ; k < lle ; k++) if(t1[j + k] != s[i][0][k]){ flag = 0 ; break ; }
					if(flag) a.push_back(flag - 1) ; 
					flag = j + 1 ; 
					for(int k = 0 ; k < lle ; k++) if(t2[j + k] != s[i][1][k]){ flag = 0 ; break ; }
					if(flag) b.push_back(flag - 1) ; 
				}
//				cout << a.size() << " " << b.size() << "\n" ;  
				int ll = 0 , rr = 0 ; 
				while(ll < a.size() && rr < b.size()){
					if(a[ll] < b[rr]) ll++ ; 
					else if(a[ll] == b[rr]){
						if(a[ll] <= l + 1 && a[ll] + lle >= r) ans++ ; 
						break ; 
					}
					else rr++ ; 
				}
			}
		}
		else ; 
		cout << ans << "\n" ; 
	}
	return 0 ;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/

