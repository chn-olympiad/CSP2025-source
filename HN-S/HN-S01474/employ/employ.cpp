#include<bits/stdc++.h>
using namespace std;
int ans = 0;
const int ma = 510;
int a[ma];
int n, m;
int c[ma];
string s;
bool vis[ma];
bool check(){
	int cnt = 0, fq = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '1' && fq < a[i]){
			cnt++;
		}else{
			fq++;
		}
	}
	return cnt >= m;
}
void dfs(int step){
	if(step > n){
		if(check()){
			ans++;
			ans %= 998224353;
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			a[step] = c[i];
			vis[i] = 1;
			dfs(step + 1);
			a[step] = 0;
			vis[i] = 0;
		}
	} 
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}

