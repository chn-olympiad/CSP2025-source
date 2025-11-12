#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 +50;
int t , xianzhi , c1 , c2 , c3 , n;
struct Node{
	ll a[4];
}node[N];

ll dfs(ll ans , ll c1 , ll c2 , ll c3 , ll sum){
	if(sum == n+1){
		return ans;
	}
	ll now = ans;
	if(c1 < xianzhi) ans = max(ans , dfs(now+node[sum].a[1] , c1+1 , c2 , c3 , sum+1));
	if(c2 < xianzhi) ans = max(ans , dfs(now+node[sum].a[2] , c1 , c2+1 , c3 , sum+1));
	if(c3 < xianzhi) ans = max(ans , dfs(now+node[sum].a[3] , c1 , c2 , c3+1 , sum+1));
	return ans;
}

int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	scanf("%d" , &t);
	while(t--){
		memset(node , 0 , sizeof(node));
		scanf("%d" , &n);
		xianzhi = n>>1;
		ll ans = 0;
		c1 = c2 = c3 = 0;
		for(int i = 1 ; i <= n ; i++){
			scanf("%lld%lld%lld" , &node[i].a[1] , &node[i].a[2] , &node[i].a[3]);
		}
		ans = dfs(0 , 0 , 0 , 0 , 1);
		printf("%lld\n" , ans);
	}
	return 0;
} 
