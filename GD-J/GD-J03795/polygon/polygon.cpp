#include<bits/stdc++.h>
using namespace std;
short n,a[5005],k;
long long mod=998244353,ans;
bool p=1;
void dfs(short ma,int sum,short s,short f){
	if(f==k&&sum>ma*2)ans=(ans+1)%mod;
	for(int i=s;i<=n;++i){
		dfs(max(ma,a[i]),sum+a[i],i+1,f+1);
	}
}
long long qp(int a,int b){
	int x=1;
	while(b){
		if(b&1){
			x=(x*a)%mod;
			a=(a*a)%mod; 
		}
		b>>=1;
	}
	return x;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)p=0;
	}
	if(n==3){
		if(max({a[1],a[2],a[3]})*2<a[1]+a[2]+a[3])cout<<1;
		else cout<<0;
	}else if(p==1&&n>20){
		long long s=n;
		ans=1+s;
		for(int i=n-2;i>=3;--i){
			long long xs=qp(n-i,mod-2);
			s=((s*(i+1))%mod*xs)%mod;
			ans=(ans+s)%mod;
		}
		cout<<ans;
	}else{
		for(int i=3;i<=n;++i){
			k=i;
			dfs(-1,0,1,0);
		}
		cout<<ans;		
	}
	return 0;
}
