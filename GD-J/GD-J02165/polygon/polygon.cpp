#include<iostream>
#include<cstdio>
using namespace std;
const int N = 5001, mod = 998244353;
int n, a[N], ans;
bool vis[N], F = true;
void dfs(int step){
	if(step > n){
		int sum = 0;
		for(int i = 1; i <= n; i++){
			if(vis[i]) sum += a[i];
		}
		for(int i = 1; i <= n; i++){
			if(vis[i]){
				if(sum <= 2 * a[i]){
					return;
				}
			}
		}
		ans++;
		return;
	}
	vis[step] = false;
	dfs(step + 1);
	vis[step] = true;
	dfs(step + 1);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1) F = false;
	}
	if(F){
		int k = 1;
		for(int i = 1; i <= n; i++){
			k *= 2;
			k %= mod;
		}
		cout << k - n * n;
		return 0;
	}
	dfs(1);
	cout << ans - 1;
	return 0;
}
