#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const long long mod=998244353;
long long n;
long long a[5005];
inline long long ksm(long long a,long long b){
	long long ret=1;
	while(b){
		if(b&1) ret=ret*1ll*a%mod;
		b>>=1;
		a=1ll*a*a%mod;
	}
	return ret%mod;
}
long long ans=0;
long long f[5005][5];
long long t[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	if(n==3){
		if((a[1]+a[2]+a[3])>a[3]*2){
			cout<<1<<'\n';
			return 0;
		}else{
			cout<<0<<'\n';
			return 0;
		}
	}
	ans=ksm(2ll,n)-n-1;
	ans=(ans%mod+mod)%mod;
	ans%=mod;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ans=(ans%mod+mod-t[j])%mod;
		}
		for(int j=a[n];j>=1;j--){
			if(j+a[i]<=a[n]){
				t[j+a[i]]+=t[j];
				t[j+a[i]]%=mod;
			}
		}
		t[a[i]]++;
	}
	cout<<(ans%mod+mod)%mod<<'\n';
	return 0;
}
