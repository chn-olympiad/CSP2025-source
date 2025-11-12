#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
#define mod 998244353
int n;
int a[N];
int dfn[N], cnt, ans;
void dfs(int pos){
	if(pos == n + 1){
		int mx = 0, sum = 0;
		for(int i = 1; i <= cnt; i++){
			mx = max(mx, dfn[i]);
			sum += dfn[i];
		}
		if(sum > mx * 2) ans++;
	}
	else{
		dfn[++cnt] = a[pos];
		dfs(pos + 1);
		cnt--;
		dfs(pos + 1);
	}
}
void solveDFS(){
	dfs(0);
	cout << ans / 2;
	exit(0);
}
int msm(int x, int k){
	for(int i = 1; i <= k; i++) x = (x * k) % mod;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int flagA1 = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1) flagA1 = 0;
	}
	
	if(n <= 20){
		solveDFS();
	}
	
	else if(flagA1 == 1){
		cout << (long long)(pow(2, n) - 1 - n - n * (n - 1) / 2) % mod;
		return 0;
	}
	   return 0;
}

