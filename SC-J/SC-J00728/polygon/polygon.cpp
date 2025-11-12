#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],ans=0;
void dfs(int i,int l,int maxn,int sum){
	if(l>=3){
		if(maxn*2<sum) ans++,ans%=998244353;
	}
	if(i>n) return;
	for(int j=i+1;j<=n;j++){
		dfs(j,l+1,max(maxn,a[j]),sum+a[j]);
	}
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
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i],a[i]);
		ans%=998244353;
	}
	cout<<ans%998244353;
	return 0;
}