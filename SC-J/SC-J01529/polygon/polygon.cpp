#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int a[N] , n , f[N] , vis[N];
long long ans = 0;
long long INF = 998244353;
map<int , bool> mp;
void dfs(int p , int k){
	if(p == k + 1){
		long long s = 0;
		int mx = 0;
		for(int i = 1; i <= k; i++){
			s += f[i];
			mx = max(f[i] , mx);
		}
		if(s >= mx && !mp[s]) ans++ , mp[s] = 1;
		return ;
	} else {
		for(int i = 1; i <= p + 1; i++){
			if(!vis[i]){
				f[p] = a[i];
				vis[i] = 1;
				dfs(p + 1 , k);
				vis[i] = 0;
			}	
		}
	}
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	bool p = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1) p = 1;
	}
	if(!p){
		for(int i = 4; i < n; i++){
			long long k = 1;
			for(int j = i + 1; j <= n; j++){
				k = k * j % INF;
			}
			for(int j = 1; j <= n - i; j++){
				k /= j;
			}
			ans += k;
		}
		if(n == 3) cout << 0;
		else if(n == 4) cout << 1;
		else cout << (ans + 1) % INF;
	} else if(n <= 20){
		long long s = 0;
		for(int i = 3; i <= n; i++){
			memset(vis , 0 , sizeof(vis));
			ans = 0;
			dfs(1 , i);
			s = (s + ans) % INF;
		}
		cout << s - 1;	
	} else cout << 0;
	return 0;
}