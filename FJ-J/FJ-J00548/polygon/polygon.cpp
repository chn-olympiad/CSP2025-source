#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
const int mod = 998244353;

int n,a[N],ans,sum[N] = {1};
bool vis[N];

void dfs(int k,int sum,int mx){
	if(sum > mx*2)ans++;
	for(int i=k+1;i<=n;i++){
		if(!vis[i]){
			vis[i] = true;
			dfs(i,sum + a[i],max(mx,a[i]));
			vis[i] = false;
		}
	}
	return;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n > 20){
		for(int i=1;i<=n;i++){
			sum[i] = sum[i-1] * i % mod;
		}
		for(int i=3;i<=n;i++){
			ans = (ans + sum[n] / sum[i] / sum[n-i])%mod;
		}
		cout << ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(0,0,0);
	cout << ans;
	return 0;
}
