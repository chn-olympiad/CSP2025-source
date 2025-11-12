#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define N 5005
using namespace std;

int n;
int a[N];
int ans;

void dfs(int k,int sum,int maxn){
	if (k > n){
		if (sum > maxn*2) ans++;
		ans %= mod;
		return;
	}
	dfs(k+1,sum+a[k],max(maxn,a[k]));
	dfs(k+1,sum,maxn);
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;++i) cin >> a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout << ans % mod;
	
	
	
	
	
	
	return 0;
} 
