#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 10;
ll a[maxn];
ll n, m;
string s;
ll last[maxn];
bool vis[maxn];
ll ans;
bool check(){
	ll lose = 0, sum = 0;
	for(int i = 1 ; i <= n ; i++){
		if(lose >= a[last[i]]){
			lose++;
			continue;
		}
		if(s[i - 1] == '1'){
			lose = 0;
			sum++;
		}else{
			lose++;
		}
	}
	return sum >= m;
}
void dfs(int x){
	if(x > n){
		if(check()){
			ans++;
		}
		return ;
	}
	for(int i = 1 ; i <= n ; i++){
		if(!vis[i]){
			vis[i] = true;
			last[x] = i;
			dfs(x+1);
			vis[i] = false;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1 ; i <= n ; i++)cin >> a[i];
	dfs(1);
	cout << ans;
	return 0;
}
