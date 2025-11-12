#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
string s1;
int c[maxn] , n;
long long ans = 0;
const int mod = 998244353;
int vis[maxn];
bool check(int m){
	int cnt = 0 , as = 0;
	for(int i = 1 ; i <= n ; i++){
//		cout << vis[i] << ' ';
		if(s1[i - 1] == '0'){
			++cnt;
		}
		else if(cnt >= c[vis[i]]){
			++cnt;
		}
		else{
			++as;
		}
	}
//	cout << '\n';
	return as >= m;
}
void dfs(int num , int m){
	if(num > n){
		if(check(m)){
			ans++;
		}
		return;
	}
	for(int i = 1 ; i <= n ; i++){
		if(!vis[i]){
			vis[num] = i;
			dfs(num + 1 , m);
			vis[num] = vis[i] = 0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	int m;
	cin >> n >> m;
	cin >> s1;
	for(int i = 1 ; i <= n ; i++){
		cin >> c[i];
	}
	dfs(1 , m);
	cout << ans;
	return 0;
}
