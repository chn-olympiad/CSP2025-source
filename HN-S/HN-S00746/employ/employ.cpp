#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,mod=998244353;

int n,m,a[N],c[N],vis[N],ss,cc,ans,tc[N],fac[N];
string sss;

int qpow(int x,int y){
	int sum=1;
	while(y){
		if(y&1) sum=sum*x%mod;
		x=x*x%mod;
		y/=2; 
	}
	return sum;
}

int A(int x,int y){
	if(x<y) return 0;
	return fac[x]*qpow(fac[x-y],mod-2)%mod;
}

int C(int x,int y){
	if(x<y) return 0;
	return fac[x]*qpow(fac[x-y],mod-2)%mod*qpow(fac[y],mod-2)%mod;
}

void dfs(int dep,int qu){
	if(n-qu<m) return ;
	if(dep-1-qu>=m){
		ans+=A(n-dep+1,n-dep+1);
		ans%=mod;
		return ;
	} 
	if(dep==n+1){
		if(n-qu>=m) ans++;
		if(ans>=mod) ans-=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(c[i]<=qu || a[dep]==0) dfs(dep+1,qu+1);
		else dfs(dep+1,qu);
		vis[i]=0;
	}
}
//rp++
//CCFrangwoguoba 
//I love CCF very much! 
//I love CCF very much! 
//I love CCF very much! 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	cin>>sss;
	for(int i=1;i<=n;i++){
		a[i]=sss[i-1]-'0';
		if(a[i]) ss++;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0) cc++;
		tc[c[i]]++;
	}
	if(ss<m){
		cout<<0;
	}else if(m==1){
		ss=0; 
		ans=0;
		for(int i=1;i<=n;i++){
			tc[i]+=tc[i-1];
			if(a[i]==1){
				if(ss==0) ans=1;
				ans=ans*max(tc[i-1]-ss,0ll)%mod;
				ss++;
			} 
		}
		ans=ans*A(n-ss,n-ss)%mod;
		cout<<(A(n,n)-ans+mod)%mod;
	}else if(m==n){
		if(tc[0]) cout<<0;
		else cout<<A(n,n);
	}else{
		dfs(1,0);
		cout<<ans;
	}
	
	return 0;
}

