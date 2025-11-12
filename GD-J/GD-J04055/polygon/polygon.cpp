#include <bits/stdc++.h>
using namespace std;
long long ans,n,a[5005];
void dfs(int q,int now,int la,long long maxn,long long sum) {
	if(now == q) {
		if(sum > maxn * 2) {
			ans++;
			ans %= 998244353; 
		}
		return ;
	}
	if(la == n) {
		return ;
	}
	for(int i = la+1; i<=n; i++) {
		dfs(q,now+1,i,max(maxn,a[i]),sum + a[i]);
	}
	return ;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int t = 3; t <= n; t++) {
		dfs(t,0,0,-1,0);
	}
	cout << ans;
	return 0;
}
