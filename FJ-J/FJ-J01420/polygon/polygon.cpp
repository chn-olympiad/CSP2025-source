#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans;
int a[5001];
void dfs(int step,int sum,int maxa){
	if(step==n+1){
		if(maxa*2<sum){
			ans=(ans+1)%mod;
		}
		return;
	}
	dfs(step+1,sum,maxa);
	dfs(step+1,sum+a[step],max(maxa,a[step]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		m=max(m,a[i]);
	}
	if(m==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*2)%mod;
		}
		ans=ans-1-n-n*(n-1)/2;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

