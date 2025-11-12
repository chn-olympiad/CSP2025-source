#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 15;
ll ans;
int n,m,t[4],k;
struct qq{
	ll x,y,z;
}a[N];
bool cmp(qq x,qq y){
	return x.x > y.x;
}
void dfs(int id,int x,int y,int z,ll sum){
	if(id > n){
		ans = max(ans,sum);
		return; 
	}
	if(x < k){
		dfs(id + 1,x + 1,y,z,sum + a[id].x);
	}
	if(y < k){
		dfs(id + 1,x,y + 1,z,sum + a[id].y);
	}
	if(z < k){
		dfs(id + 1,x,y,z + 1,sum + a[id].z);
	}
	return ;
}
void solve(){
	ans = 0;
	cin >> n;
	k = n / 2;
	m = 3;
	for(int i = 1,x,y,z;i <= n;i ++){
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	ans = 0;
	dfs(0,0,0,0,0);
	cout << ans << '\n';
}
int main(){
//	freopen("club2.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _;
	cin >> _;
	while(_ --){
		solve();
	}
	return 0;
} 
