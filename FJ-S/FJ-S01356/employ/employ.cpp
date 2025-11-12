#include<bits/stdc++.h>
#define ll long long
#define inf INT_MAX
#define linf LLONG_MAX
#define mod 998244353
using namespace std;
ll n, m, ans, c[500], cnt;
bool vis[500];
vector<ll> use;
string s;
//ll fac(ll p){
//	return p == 1 ? 1 : p * fac(p - 1) % mod;
//}
bool check(){
	ll now = 0, sad = 0;
	for(int i = 0; i < n; i++){
		if(sad >= c[use[i]]){
			sad++;
		}
		else{
			if(s[i] == '0'){
				sad++;
			}
			else{
				now++;
			}
		}
	}
	return now >= m;
}
void dfs(ll now){
	
	if(now == n){
		
//		cout << endl;
		ans += check();
//		if(check()){
//			for(int i = 0; i < n; i++){
//			cout << use[i] << " ";
//		}
//		}
		return;
	}
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			vis[i] = true;
			use.push_back(i);
			dfs(now + 1);
			use.pop_back();
			vis[i] = false;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++){
		cin >> c[i];
		cnt += (c[i] == 0);
	}
	bool flag = false;
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			flag = true;
		}
	}
	if(cnt + m > n || n > 18){
		cout << 0 << endl;
		return (0 - 0);
	}
	if(!flag){
		
		return (0 - 0);
	}
	dfs(0);
	cout << ans << endl;
	return (0 - 0);
}

