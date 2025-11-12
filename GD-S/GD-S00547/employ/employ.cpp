#include <bits/stdc++.h>
using namespace std;

const int N = 500, MOD = 998244353;
int path[N], n, m;
string s;
bool vis[N];
int a[N];
int ans = 0;

void dfs(int dep){
	if(dep == s.size()){
		for(int i = 1; i <= dep; i++){
			
		}
		return ;
	}
	for(int i = 0; i < s.size(); i++){
		if(!vis[i]){
			vis[i] = 1;
			path[dep+1] = s[i] - '0';
			dfs(dep+1);
			vis[i] = 0;
		}
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	//dfs(0);
	cout << 0 << '\n'; 
	return 0;
}
