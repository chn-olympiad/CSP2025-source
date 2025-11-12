//wonder:40pts 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int a[5005];
int b[5005],c[5005],d[5005],e[5005];
int ans = 0;
void dfs(int cur,int n,int maxn,int sum){
	if(cur == n + 1){
		if(sum > maxn) ans++;
		ans %= mod;
		return;
	}
	dfs(cur+1,n,a[cur],sum + maxn);
	dfs(cur+1,n,maxn,sum);
}
void work(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	dfs(1,n,0,0);
	cout << ans % mod;
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int t = 1;
//	cin >> t;
	while(t--){
		work();
		if(t) cout << endl;
	}
}
