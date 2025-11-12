#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
int n,k,ans;
int a[N],sum[N];
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool fl=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) fl=1;
	}
	if(n<=20){
		for(int i=0;i<(1<<n);i++){
			int sum=0,mx=0;
			for(int j=1;j<=n;j++){
				if(i>>(j-1)&1)
					sum+=a[j],mx=max(mx,a[j]); 
			} 
			if(sum>2*mx) ans++,ans%=mod;
		}
	}
	else if(!fl){
		ans=(qpow(2,n)%mod-1-n+mod-n*(n-1)%mod*qpow(2,mod-2)+mod)%mod; 
	}
	cout<<ans;
	return 0;
} 