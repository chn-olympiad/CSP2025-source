#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M = 998244353;
int n , m , s[505] , c[505] , ans , p[505];
bool vis[505];
void dfs(int x , int y , int z){
	if( x > n ){
		ans += ( y >= m );
		return;
	}
	for( int i = 1 ; i <= n ; i++ ){
		if(vis[i]) continue;
		vis[i] = 1;
		if( z >= c[i] ) dfs(x + 1 , y , z + 1);
		else dfs(x + 1 , y + s[x] , z + 1 - s[x]);
		vis[i] = 0;
	}
}
signed main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for( int i = 1 ; i <= n ; i++ ){
		char x;
		cin >> x;
		s[i] = x - '0';
	} 
	for( int i = 1 ; i <= n ; i++ ) cin >> c[i];
	dfs(1 , 0 , 0);
	cout << ans;
	return 0;
} 
