#include <bits/stdc++.h>
//#define int long long
#define lowbit(x) ((x) & -(x))
#define PII pair < int , int >
#define x first
#define y second
using namespace std ;
const int N = 1e5 + 5 ; 
int n , a[N][3] , d[N][3] , sum[3] ; 
bool cmp(int x , int y){ return sum[x] > sum[y] ; }
bool cmp1(int x , int y){
	if(a[x][d[x][0]] - a[x][d[x][1]] == a[y][d[y][0]] - a[y][d[y][1]])
		return a[x][d[x][0]] - a[x][d[x][2]] < a[y][d[y][0]] - a[y][d[y][2]] ; 
	return a[x][d[x][0]] - a[x][d[x][1]] < a[y][d[y][0]] - a[y][d[y][1]] ; 
}
signed main(){
	freopen("club.in" , "r" , stdin) ;
	freopen("club.out" , "w" , stdout) ;
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	int T ; cin >> T ; 
	while(T--){
		cin >> n ; vector < int > v ; int ans = 0 ;  
		set < PII > st ; 
		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j < 3 ; j++) cin >> a[i][j] , st.insert({-a[i][j] , j}) ; 
			for(int j = 0 ; j < 3 ; j++) d[i][j] = (*st.begin()).y , st.erase(st.begin()) ; 
			sum[d[i][0]]++ ; ans += a[i][d[i][0]] ; 
		}
		v.push_back(0) ; v.push_back(1) ; v.push_back(2) ; 
		sort(v.begin() , v.end() , cmp) ; 
//		cout << v[0] << " " << sum[v[0]] << " " ; 
		if(sum[v[0]] > n / 2){
			vector < int > b ; 
			for(int i = 1 ; i <= n ; i++) if(d[i][0] == v[0]) b.push_back(i) ; 
			sort(b.begin() , b.end() , cmp1) ; 
			for(int i : b){
				sum[v[0]]-- ; 
				ans = ans - a[i][d[i][0]] + a[i][d[i][1]] ; 
				if(sum[v[0]] <= n / 2) break ;
			}
		}
		cout << ans << "\n" ; 
		sum[0] = sum[1] = sum[2] = 0 ; 
		st.clear() ; 
	} 
	return 0 ;
}
/*
考虑移除某些人到别的部门
 
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

