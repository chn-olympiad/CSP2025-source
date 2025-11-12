#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n , T , dp[N][4] , cnt[N][4][4];
struct node{
	int d1 , d2 , d3;
}a[N];
bool cmp(node a , node b){
	return a.d1>b.d1;
}
bool cmp2(node a , node b){
	return a.d2>b.d2;
}
bool cmp1(node a , node b){
	return a.d3>b.d3;
}
int main(){
	
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);	
	
	
	cin >> T;
	while(T--){
		cin >> n;
		bool flag = true;
		bool flag1 = true;
		bool flag2 = true;
		for(int i = 1;i <= n;i ++){
			cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
			if(a[i].d2 != 0 || a[i].d3 != 0)	flag = false;
			if(a[i].d1 != 0 || a[i].d2 != 0)	flag1 = false;
			if(a[i].d1 != 0 || a[i].d3 != 0)	flag2 = false;
		}
		if(n == 2){
			int ans = max(a[1].d1+a[2].d2 , max(a[1].d1+a[2].d3 , max(a[1].d2+a[2].d1 , max(a[1].d2+a[2].d3 , max(a[1].d3+a[2].d1 , a[1].d3+a[2].d2)))));
			cout << ans << "\n";
			continue;
		}
		memset(dp , 0 , sizeof dp);
		memset(cnt , 0 , sizeof cnt);
		if(flag){
			int ans = 0;
			sort(a + 1 , a + n + 1 , cmp);
			for(int i = 1;i <= n/2;i ++){
				ans += a[i].d1;
			}
			cout << ans << "\n";
			continue;
		}if(flag1){
			int ans = 0;
			sort(a + 1 , a + n + 1 , cmp1);
			for(int i = 1;i <= n/2;i ++){
				ans += a[i].d3;
			}
			cout << ans << "\n";
			continue;
		}if(flag2){
			int ans = 0;
			sort(a + 1 , a + n + 1 , cmp2);
			for(int i = 1;i <= n/2;i ++){
				ans += a[i].d2;
			}
			cout << ans << "\n";
			continue;
		}
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= 3;j ++){
				for(int k = 1;k <= 3;k ++){
						if(j == 1) dp[i][j] = max(dp[i][j] , dp[i-1][k]+a[i].d1);
						if(j == 2) dp[i][j] = max(dp[i][j] , dp[i-1][k]+a[i].d2);
						if(j == 3) dp[i][j] = max(dp[i][j] , dp[i-1][k]+a[i].d3);
				}
			}
		}
		cout << max(dp[n][1] , max(dp[n][2] , dp[n][3])) << "\n";
	}
		
	return 0;
}
