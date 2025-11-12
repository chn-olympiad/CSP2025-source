#include<bits/stdc++.h>
using namespace std;
int n , a[5005];
const int mod = 998244353;
long long ans = 0;
void dfs(int cur , int sum , int mx , int cnt){
	if(cur == n + 1){
		if(sum > 2 * mx && cnt >= 3){
			ans = (ans + 1) % mod;
		}
		return ;
	}
	dfs(cur + 1 , sum + a[cur] , max(mx , a[cur]) , cnt + 1);
	dfs(cur + 1 , sum , mx , cnt);
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d" , &a[i]);
	}
	dfs(1 , 0 , -1e9 , 0);
	printf("%lld" , ans);
	return 0;
}