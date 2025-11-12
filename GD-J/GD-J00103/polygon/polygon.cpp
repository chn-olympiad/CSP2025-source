#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n, maxn=-1, a[5005];
long long ans;
int dfs(int k, int x, int y){
	if(k>n){
		if(x>y+y) return 1;
		return 0;
	}else{
		int w;
		w=(dfs(k+1, x, y)%mod+dfs(k+1, x+a[k], max(y, a[k])%mod))%mod;
		return w;
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if(a[i]>maxn) maxn=a[i];
	}
	if(maxn==1){
		ans=(n*(n-1)*(n-2)/6)%mod;
		cout<<ans;
	}
	ans=dfs(1,0,0);
	cout<<ans;
	return 0;
}

