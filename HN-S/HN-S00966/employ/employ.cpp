#include<bits/stdc++.h>
#define int long long
using namespace std;
const int kN = 500 + 7;
int n, m;
int s[kN], c[kN], ans;
bool vis[kN];
void dfs(int cur, int sum){
	if(cur > n){
		if(n - sum >= m){
			ans++;
		}
		return ;
	}
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			vis[i] = 1;
			if(sum >= c[i]){
				dfs(cur + 1, sum + 1);
			}else{
				dfs(cur + 1, sum + (s[i] == 0));
			}
			vis[i] = 0;
		}
	}
	return ;
}
signed main(){
	froepen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		char c;
		cin >> c;
		if(c == '1'){
			s[i] = 1;
		}else{
			s[i] = 0;
		} 
	}
	for(int i = 1; i <= n; ++i){
		cin >> c[i];
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
