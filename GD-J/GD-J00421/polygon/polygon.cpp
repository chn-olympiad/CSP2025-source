#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[5001], e;
bool vis[5001];
void dfs(ll sum, ll maxn, ll st){
	if(sum > maxn*2){
		e++;
	}
	for(ll i = st+1; i <= n; i++){
		if(!vis[i] ){
			vis[i] = 1;
			dfs(sum + a[i], max(maxn, a[i]), i);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	dfs(0, 0, 0);
	cout << e%998244353;
	return 0;
}
