#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[10005],dp[5005],ans;
void dfs(int k,int l,int sum){
	if(k=0){
		if(sum>a[l]*2)
		ans++;
		return ;
	}
	for(l=l+1;l<=n;l++){
		dfs(k--,l,sum+a[l]); 
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(i,0,0);
	}
	cout<<ans;
} 
