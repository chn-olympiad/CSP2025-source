#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans,f;
void dfs(int now,int mx,int sum,int cnt){
	if(now>=n+1){
		if(mx*2<sum&&cnt>=3)	ans=(ans+1)%mod;
		return;
	}
	if(mx<a[now])	dfs(now+1,a[now],sum+a[now],cnt+1);
	else dfs(now+1,mx,sum+a[now],cnt+1);
	dfs(now+1,mx,sum,cnt);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)	f=1;
	}
	if(n<=2)	cout<<0;
	else if(n<=20){
		dfs(1,0,0,0);
		cout<<ans%mod;
	}
	else if(!f){
		ans=1;
		for(int i=1;i<=n;i++)	ans=ans*2%mod;
		ans=(ans-n*(n-1)/2-n-1)%mod;
	}
	return 0;
}

