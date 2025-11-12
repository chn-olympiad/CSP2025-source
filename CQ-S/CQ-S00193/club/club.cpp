#include <bits/stdc++.h>
using namespace std;
#define FILE_OPEN
int t;
struct node{
	int val, i , j , s[4];
	node(){}
	node(int val , int i , int j) :
		val(val) , i(i) , j(j) {}
	bool friend operator<(node i , node j){
		return i.val < j.val;
	}
}; 
priority_queue<node> q;
const int maxn = 1e5 + 5;
int a[maxn][4] , b[maxn];
int dp[210][105][105][105];
int main(){
	#ifdef FILE_OPEN
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	#endif
	cin.tie(0) , cout.tie(0) -> sync_with_stdio(0);
	cin >> t;  
	bool isallzero = 1;
	while(t --){
		memset(dp , 0 , sizeof dp);
		int n , nhalf , Val = 0 , s[4]{};
		cin >> n;
		nhalf = n >> 1;
		
		for(int i = 1; i <= n; i ++){
			for(int j = 1 ; j <= 3 ; j ++)cin >> a[i][j];
			b[i] = a[i][1];
			if(a[i][2] != 0 || a[i][3] != 0)isallzero = 0;
		}
		if(isallzero){
			sort(b + 1, b + n + 1 , greater<>());
			int sum = 0;
			for(int i = 1 ; i <= nhalf ; i ++){
				sum += b[i];
			}
			cout << sum << "\n";
			continue;
		}
		int ans = 0;
		
		for(int i = 1 ; i <= n ; ++i){
			for(int j = 0 ; j <= nhalf ; ++j){
				for(int k = 0 ; k <= nhalf ; ++k){
					for(int l = 0 ; l <= nhalf ; ++l){
						if(j == 0 && k == 0 && l == 0)continue; 
						dp[i][j][k][l] = max({(j > 0) ? dp[i - 1][j - 1][k][l] + a[i][1] : 0,
											(k > 0) ? dp[i - 1][j][k - 1][l] + a[i][2] : 0,
					    					(l > 0) ? dp[i - 1][j][k][l - 1] + a[i][3] : 0});
//					   cout << i << " " << j << " " << k << " " << l << " " << dp[i][j][k][l]<< "\n";
					} 
				}
			}
		}
		for(int j = 0 ; j <= nhalf ; ++j)
			for(int k = 0 ; k <= nhalf ; ++k)
				for(int l = 0 ; l <= nhalf ; ++l)
					ans = max(ans , dp[n][j][k][l]);
		cout << ans << '\n';
	}
	return 0;
}
/*
3
4
4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0*/
