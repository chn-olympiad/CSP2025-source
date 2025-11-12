#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=5e3+5;
const int mod=998244353;
int a[N],fac[N];
int cs[N];
int ans;
inline void Dfs(int x){
	if(x==n+1){
		int cnt=0,sum=0,maxx=-1;
		for(int i=1;i<=n;i++){
			if(cs[i]){
				sum+=a[i];
				maxx=max(a[i],maxx);
				cnt++;
			}
		}
		if(cnt<3||maxx*2>=sum)	return ;
		ans++;
		ans%=mod;
		return ;
	}
	Dfs(x+1);
	cs[x]=1;
	Dfs(x+1);
	cs[x]=0;
}
inline int qpow(int a,int b){
	int base=a,res=1;
	while(b){
		if(b&1){
			res*=base;
			res%=mod;
		}
		base*=base;
		base%=mod;
		b>>=1;
	}
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n<=20){
		Dfs(1);
	}
	else{//111111
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1)  cnt++;
	}
	int t=n;
	#define n cnt
		fac[0]=fac[1]=1;
		for(int i=2;i<=n;i++)	fac[i]=fac[i-1]*i,fac[i]%=mod;
		for(int m=3;m<=n;m++){
			ans+=(fac[n]/qpow(fac[m],mod-2)/qpow(fac[n-m],mod-2));
			ans%=mod;		
		}
		ans+=(fac[n]/qpow(fac[2],mod-2)/qpow(fac[n-2],mod-2))*(t-n);
		ans%=mod;
	}
	cout<<ans%mod;
}
 
