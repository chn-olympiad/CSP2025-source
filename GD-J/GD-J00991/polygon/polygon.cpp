#include<bits/stdc++.h>
using namespace std;
long long n,f1=1,a[5005],cnt,ans,x,y,mod=998244353;
void dfs(long long s,long long sum,int use){
	if(use>=2&&sum>a[s]){
		ans++;
		ans%=mod;
	}
	if(s==n)
	return;
	dfs(s+1,sum+a[s],use+1);
	dfs(s+1,sum,use);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)
		f1=0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])
		cout<<1;
		else
		cout<<0;
		return 0;
	}
	if(f1){
		x=2,y=n*(n-1);
		for(int i=3;i<=n;i++){
			x=x*i;
			y=y*(n-i+1);
			ans+=y/x;
			ans%=mod;
		} 
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
