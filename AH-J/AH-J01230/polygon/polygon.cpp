#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans,mod=998244353;
long long jc[5005];
void dfs(int k,int sum,int maxn,int g){
	if(k>n){
		if(g>2&&sum>(maxn<<1)) ans++;
		return;
	}
	dfs(k+1,sum+a[k],max(maxn,a[k]),g+1);
	dfs(k+1,sum,maxn,g);
}
int check(){
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	return sum;
}
long long mp(long long k){
	long long op=mod-2,sum=1;
	while(op){
		if(op%2) sum=sum*k%mod;
		k=k*k%mod;
		op/=2;
	}
	return sum;
}
void init(){
	jc[1]=1;
	for(int i=2;i<=n;i++)
		jc[i]=(jc[i-1]*i)%mod;
}
long long c(int k){
	return (jc[n]*mp(jc[n-k])%mod*mp(jc[k]))%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
	}
	else if(check()==n){
		init();
		for(int i=3;i<n;i++){
			ans=(ans+c(i))%mod;
		}
		cout<<ans+1;
	}
	return 0;
}
