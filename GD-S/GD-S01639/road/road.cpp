/*********************
 ~AUTHOR BY "ILWF^_^"
 ~author by "ILWF^_^"
*********************/
#include<bits/stdc++.h>
#define ILW return
#define F 0
using namespace std;
using ll = long long;
const ll N = 20005 , M = 2000005;
const ll mod = 1e9 + 7;
struct side{
	ll u , v , w , id;
}sid[M];
ll c[N] , p[N] , sta[15];
ll n , m , k;
bool cmp(side x , side y){
	ILW x.w < y.w;
}
ll find(ll x){
	if(x != p[x]) p[x] = find(p[x]);
	ILW p[x];
}
void init(){
	sort(sid + 1 , sid + m + 1 , cmp);
}
ll kruskal(){
	for(int i = 1;i <= n + k;i++) p[i] = i;
	ll res = 0;
	for(int i = 1;i <= m;i++){
		if(sta[sid[i].id] == 0) continue;
		ll a = find(sid[i].u) , b = find(sid[i].v);
		if(a == b) continue;
		res += sid[i].w;
		p[a] = b;
	}
	ILW res;
}
ll ans = 1e17;
void dfs(ll pos , ll val){
	if(pos == k + 1){
		ans = min(ans , kruskal() + val);
		ILW;
	}
	sta[pos] = 0;
	dfs(pos + 1 , val);
	sta[pos] = 1;
	dfs(pos + 1 , val + c[pos]);
}
void solve(){
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> sid[i].u >> sid[i].v >> sid[i].w;
	bool flag = true;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		if(c[i] != 0) flag = false;
		for(int j = 1;j <= n;j++){
			sid[++m].u = n + i , sid[m].v = j;
			cin >> sid[m].w;
			sid[m].id = i;
		}
	}
	init();
	if(flag == true){
		for(int i = 0;i <= k;i++) sta[i] = 1;
		cout << kruskal();
	}else{
		sta[0] = 1;
		dfs(1 , 0);
		cout << ans;
	}
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
	//cin >> t;
	while(t--) solve();
	ILW F;
}
