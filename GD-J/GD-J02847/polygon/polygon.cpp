#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010, inf = 998244353;
int a[maxn], st[maxn], tag, n;
long long ans;
void dfs(int deep, int mx, int sum, int t){
	if(deep == tag){
		if(sum > mx * 2){
			ans++, ans %= inf;
			//cout << sum << '\n';
		} 
		return ;
	}
	for(int i = t + 1; i <= n; i++){
		if(st[i] == 0){
			st[i] = 1;
			dfs(deep + 1, max(mx, a[i]), sum + a[i], i);
			st[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(tag = 3; tag <= n; tag++) dfs(0, 0, 0, 0);
	cout << ans;
    return 0;
}
