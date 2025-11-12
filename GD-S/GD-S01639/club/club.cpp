/*********************
 ~AUTHOR BY "ILWF^_^"
 ~author by "ILWF^_^"
*********************/
#include<bits/stdc++.h>
#define ILW return
#define F 0
using namespace std;
using ll = long long;
const ll N = 200005 , M = 205;
const ll mod = 1e9 + 7;
struct student{
	ll a , b , c;
}stu[N];
struct node{
	ll diff , id;
}ab[N] , ac[N];
bool cmp(node x , node y){
	ILW x.diff < y.diff;
}
ll vis[N];
ll n , ans = 0;
void solve2(){
	fill(vis + 1 , vis + n + 1 , 0);
	for(int i = 1;i <= n;i++){
		ans += stu[i].a;
		ab[i].diff = stu[i].a - stu[i].b;
		ab[i].id = i;
		ac[i].diff = stu[i].a - stu[i].c;
		ac[i].id = i;
	}
	sort(ab + 1 , ab + n + 1 , cmp);
	sort(ac + 1 , ac + n + 1 , cmp);
	ll i , x , y , cnt1 = 0 , cnt2 = 0;
	for(i = 1 , x = 1 , y = 1;i <= n / 2;i++){
		while(vis[ab[x].id] == 1) x++;
		while(vis[ac[y].id] == 1) y++;
		ll sum1 = ab[x].diff;
		if(cnt1 == n / 2 || x == n + 1) sum1 = INT_MAX;
		ll sum2 = ac[y].diff;
		if(cnt2 == n / 2 || y == n + 1) sum2 = INT_MAX;
		if(sum1 < sum2){
			ans -= sum1;
			vis[ab[x].id] = 1;
			x++;
			cnt1++;
		}else{
			ans -= sum2;
			vis[ac[y].id] = 1;
			y++;
			cnt2++;
		}
	}
	for(;i <= n;i++){
		while(vis[ab[x].id] == 1) x++;
		while(vis[ac[y].id] == 1) y++;
		ll sum1 = ab[x].diff;
		if(cnt1 == n / 2 || x == n + 1) sum1 = INT_MAX;
		ll sum2 = ac[y].diff;
		if(cnt2 == n / 2 || y == n + 1) sum2 = INT_MAX;
		if(sum1 >= 0 || sum2 >= 0) break;
		if(sum1 < sum2){
			ans -= sum1;
			vis[ab[x].id] = 1;
			x++;
			cnt1++;
		}else{
			ans -= sum2;
			vis[ac[y].id] = 1;
			y++;
			cnt2++;
		}
	}
	cout << ans << '\n';
}
void solve1(){
	fill(vis + 1 , vis + n + 1 , 0);
	for(int i = 1;i <= n;i++){
		ans += stu[i].a;
		ab[i].diff = stu[i].a - stu[i].b;
		ab[i].id = i;
	}
	sort(ab + 1 , ab + n + 1 , cmp);
	ll i , x , cnt1 = 0;
	for(i = 1 , x = 1;i <= n / 2;i++){
		while(vis[ab[x].id] == 1) x++;
		ll sum1 = ab[x].diff;
		if(cnt1 == n / 2 || x == n + 1) break;
		ans -= sum1;
		vis[ab[x].id] = 1;
		x++;
		cnt1++;
	}
	cout << ans << '\n';
}
void dfs(ll pos , ll cnta , ll cntb , ll cntc , ll val){
	if(pos == n + 1){
		ans = max(ans , val);
		ILW;
	}
	if(cnta != n / 2) dfs(pos + 1 , cnta + 1 , cntb , cntc , val + stu[pos].a);
	if(cntb != n / 2) dfs(pos + 1 , cnta , cntb + 1 , cntc , val + stu[pos].b);
	if(cntc != n / 2) dfs(pos + 1 , cnta , cntb , cntc + 1 , val + stu[pos].c);
}
void solve3(){
	dfs(1 , 0 , 0 , 0 , 0);
	cout << ans << '\n';
}
ll dp[M][M][M];
void solve4(){
	memset(dp , 0 , sizeof(dp));
	for(ll i = 1;i <= n;i++){
		for(int j = 0;j < i;j++){
			for(int k = 0;k < i;k++){
				if(j + k >= i) continue;
				dp[i][j + 1][k] = max(dp[i][j + 1][k] , dp[i - 1][j][k] + stu[i].a);
				dp[i][j][k + 1] = max(dp[i][j][k + 1] , dp[i - 1][j][k] + stu[i].b);
				dp[i][j][k] = max(dp[i][j][k] , dp[i - 1][j][k] + stu[i].c);
			}
		}
	}
	ans = 0;
	for(int j = 0;j <= n / 2;j++){
		for(int k = 0;k <= n / 2;k++){
			ans = max(ans , dp[n][j][k]);
		}
	}
	cout << ans << '\n';
}
void solve(){
	cin >> n;
	ans = 0;
	bool flag1 = true , flag2 = true;
	for(int i = 1;i <= n;i++){
		cin >> stu[i].a >> stu[i].b >> stu[i].c;
		if(!(stu[i].c == 0)) flag2 = false;
	}
	if(flag2 == true) solve1();
	else if(n <= 17) solve3();
	else if(n <= 200) solve4();
	else solve2();
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
	cin >> t;
	while(t--) solve();
	ILW F;
}
