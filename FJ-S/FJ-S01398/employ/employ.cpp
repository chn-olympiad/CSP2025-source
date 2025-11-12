#include <bits/stdc++.h>
using namespace std;

const int N = 600;
int c[N];
int vis[N];
int ans[N];

string s;
int n, m;
long long nans = 0;

int check(){
	int p = 0; //被录用的 
	int w = 0; //被拒绝的 
	for (int i = 1; i <= n; i++){
		int x = s[i]-'0';
		if (x == 1 && w < c[ans[i]]){
			p++;
		}else{
			w++;
		}
	}
	return p;
}

void dfs(int now){
	if (now > n){
		if (check() >= m){
			nans = (nans+1)% 998244353;
		}
		return;
	}
	for (int i = 1; i <= n; i++){
		if (vis[i] == 0){
			ans[now] = i; 
			vis[i] = 1;
			dfs(now+1);
			vis[i] = 0;
		}
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	
	dfs(1);
	cout << nans % 998244353; 
} 


