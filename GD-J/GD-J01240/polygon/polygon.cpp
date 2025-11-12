#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],ans;
void dfs(int mx,int sum,int t){
	if(t==n){
		if(sum>mx*2){
			ans=(ans+1)%MOD;
		}
		return;
	}
	for(int i=t+1;i<=n;i++){
		if(i==n){
			dfs(a[i],sum+a[i],n);
			dfs(mx,sum,n);
			continue;
		}
		dfs(a[i],sum+a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
