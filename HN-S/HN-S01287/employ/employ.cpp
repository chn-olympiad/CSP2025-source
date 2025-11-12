#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
bool vis[505];
int a[505];
int d[505];
int ans;
void check(){
	int dd = 0,cnt = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(dd > a[d[i]] || s[i - 1] == '0'){
			dd ++;
			continue;
		}
		cnt ++;
	}
	ans += (cnt > m);
	return;
}
void dfs(int k){
	if(k == n + 1){
		check();
		return;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(!vis[i]){
			d[k] = i;
			vis[i] = 1;
			dfs(k + 1);
			vis[i] = 0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m >> s;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}

