#include<bits/stdc++.h>
using namespace std;
long long n,z[100];
long long ans,cnt,f,mod=998244353;
void dfs(long long p,long long m,long long s){
	if(p==n){
		if(m*2<s)ans++;
		return;
	}
	dfs(p+1,max(m,z[p]),s+z[p]);
	dfs(p+1,m,s);
	return;
}
long long s(long long a,long long b){
	long long k=1;
	while(b){
		if(b&1){
			k*=a;
			k%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return k;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>z[i];
	}
	if(n<=20){
		dfs(0,0,0);
		cout<<ans;
		return 0;
	}
	f=1*2*3;
	cnt=n*(n-1)%mod*(n-2)%mod;
	for(long long i=3;i<=n;i++){
		ans=(ans+(cnt*s(f,mod-2))%mod)%mod;
		cnt=(cnt*(n-i))%mod;
		f=f*(i+1)%mod;
	}
	cout<<ans;
	return 0;
}
/*
AK CSP-J
AK CSP-S
AK NOIP
AK 省选
AK NOI
AK IOI
*/