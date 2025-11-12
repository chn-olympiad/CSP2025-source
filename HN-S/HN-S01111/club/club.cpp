#include<bits/stdc++.h>
using namespace std;

int t , n;
int a[100005][4] , p[100005];
int maxa , maxb , dp[205][205][205];
struct cmp{
	bool operator()(int x , int y){
		return a[x][2] - a[x][1] < a[y][2] - a[y][1];
	}
};
struct Cmp{
	bool operator()(int x , int y){
		return a[x][1] - a[x][2] < a[y][1] - a[y][2];
	}
};
bool CMP(int x , int y){
	return a[x][1] > a[y][1];
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
		cin >> n;
		memset(dp , 0 , sizeof(dp));
		maxa = maxb = 0;
		for( int i = 1 ; i <= n ; i++ ){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			maxa = max( maxa , a[i][2] );
			maxb = max( maxb , a[i][3] );
		} 
		if( !maxa && !maxb ){
			for( int i = 1 ; i <= n ; i++ ) p[i] = a[i][1];
			sort(p + 1 , p + n + 1 , CMP);
			int ans = 0;
			for( int i = 1 ; i <= n / 2 ; i++ ) ans += p[i];
			cout << ans << "\n";
			continue; 
		}
		if( !maxb ){
			priority_queue<int , vector<int> , cmp> g1;
			priority_queue<int , vector<int> , Cmp> g2;
			for( int i = 1 ; i <= n ; i++ ){
				if( a[i][1] >= a[i][2] ){
					g1.push(i);
					if( g1.size() > n / 2 ){
						g2.push(g1.top());
						g1.pop();
					}
				}
				else{
					g2.push(i);
					if( g1.size() > n / 2 ){
						g1.push(g2.top());
						g2.pop();
					}
				}
			}
			int ans = 0;
			while(!g1.empty()){
				ans += a[g1.top()][1];
				g1.pop();
			}
			while(!g2.empty()){
				ans += a[g2.top()][2];
				g2.pop();
			}
			cout << ans << "\n";
			continue;
		}
		for( int i = 1 ; i <= n ; i++ ){
			for( int j = n / 2 ; j >= 0 ; j-- ){
				for( int k = n / 2 ; k >= 0 ; k-- ){
					for( int l = n / 2 ; l >= 0 ; l-- ){
						if(j)	dp[j][k][l] = max( dp[j][k][l] , dp[j - 1][k][l] + a[i][1] );
						if(k)	dp[j][k][l] = max( dp[j][k][l] , dp[j][k - 1][l] + a[i][2] );
						if(l)	dp[j][k][l] = max( dp[j][k][l] , dp[j][k][l - 1] + a[i][3] );
					}
				}
			}
		}
		int ans = 0;
		for( int i = 1 ; i <= n / 2 ; i++ ){
			for( int j = 1 ; j <= n / 2 ; j++ ){
				for( int k = 1 ; k <= n / 2 ; k++ ){
					ans = max( ans , dp[i][j][k] );
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
