#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5005];
int ans;
void dfs(int start,int maxn,int sum){
	if(start==n+1){
		if(sum>2*maxn)ans=(ans+1)%(1ll*998244353);
		return;
	}
	dfs(start+1,max(maxn,a[start]),sum+a[start]);
	dfs(start+1,maxn,sum);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans%(1ll*998244353);
	return 0;
}
