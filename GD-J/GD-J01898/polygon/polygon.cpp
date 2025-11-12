#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,ans;
int a[5005];
void dfs(int x,int num,int sum,int maxn){
	if(x==n+1){
		if(num>=3){
			if(maxn*2<sum){
				ans=(ans+1)%mod;
			}
		}
		return ;
	}
	dfs(x+1,num,sum,maxn);
	dfs(x+1,num+1,sum+a[x],max(maxn,a[x]));
}
int fp(int x,int n){
	int cnt=1,r=x;
	while(n!=0){
		if(n&1){
			cnt=cnt*r%mod;
		}
		r=r*r%mod;
		n>>=1;
	}
	return cnt%mod;
}
int ni(int x){
	return fp(x,mod-2)%mod;
}
int c[5005],inv[5005];
void init(){
	c[0]=1;
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++){
		inv[i]=ni(c[i])%mod;
	}
}
int maxn=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		init();
		for(int i=3;i<=n;i++){
			ans=(ans+c[n]*inv[n-i]%mod*inv[i]%mod)%mod;
		}
		cout<<ans+1;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans%mod;
	return 0;
}
//polygon
