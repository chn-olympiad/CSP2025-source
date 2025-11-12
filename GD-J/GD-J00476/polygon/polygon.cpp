#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5000+5,mod=998244353;
int a[maxn],dp[2][maxn],n,f[maxn],mp[maxn];
int qpow(int x,int y){
	if(y==0)return 1;
	if(y==1)return x;
	int k=qpow(x,y/2);
	k=(k*k)%mod;
	if(y%2==1)k=(k*x)%mod;
	return k;
}
int fac[maxn*10],inv[maxn*10],ans;
void init(){
	fac[0]=1;
	for(int i=1;i<maxn*10;i++)fac[i]=(fac[i-1]*i)%mod;
	inv[maxn*10-1]=qpow(fac[maxn*10-1],mod-2);
	for(int i=maxn*10-2;i>=0;i--)inv[i]=(inv[i+1]*(i+1))%mod;
}
int C(int n,int m){
	return fac[n]*inv[n-m]%mod*inv[m]%mod;
} 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	init(); 
	int t=0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		t^=1;
		for(int j=0;j<=5001;j++){
			if(a[i]<j)dp[t][j]=(dp[t^1][j]+dp[t^1][j-a[i]])%mod;
			else dp[t][j]=(dp[t^1][j]+dp[t^1][0])%mod;
		}
		if(a[i+1]!=a[i])f[i]=dp[t][a[i+1]+1];
	}
	int now=0;
	for(int i=1;i<=n+1;i++){
		if(a[i]!=a[i-1]){
			if(now>=2)ans=(ans+C(now,2)*(qpow(2,i-now-1)-1))%mod;
			for(int j=3;j<=now;j++)ans=(ans+C(now,j)*qpow(2,i-now-1))%mod;
			ans=(ans+now*f[i-now-1])%mod;
			now=1;
		}else now++; 
	}
	cout<<ans;
}
