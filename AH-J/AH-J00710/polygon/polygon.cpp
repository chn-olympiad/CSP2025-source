#include<bits/stdc++.h>
#define int long long 
#define mod 998244353
using namespace std;
bool dzdbaba,iloveccf;
int a[5005];
int n,ma;
int f(int x){
	int ans=1;
	for(int i=1;i<=x;i++){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
int p(int x,int y){
	int ans=1;
	while(y){
		if(y&1){
			ans*=x;
			ans%=mod;
		}
		y>>=1;
		x*=x;
		x=x%mod;
	}
	return ans;
}
int c(int a,int b){
	return f(a)*p(f(b)*f(a-b)%mod,mod-2)%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(ma==1){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
		}
		cout<<ans;
	}else{
		int ans=0;
		for(int i=0;i<(1ll<<n);i++){
			int s=0,ma=0;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1){
					ma=max(ma,a[j]);
					s+=a[j];
				}
			}
			if(s>2*ma){
				ans++;
				ans%=mod;
			}
		}
		cout<<ans;
	}
	return 0;
}
