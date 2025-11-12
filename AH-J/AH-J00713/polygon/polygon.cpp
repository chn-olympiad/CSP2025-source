#include<bits/stdc++.h>
using namespace std;
const int N=30,M=5010,mod=998244353;
int n,a[N],inv[M],fact[M];
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
void init(){
	fact[0]=1;
	for(int i=1;i<M;i++) fact[i]=1ll*fact[i-1]*i%mod;
	inv[M-1]=qmi(fact[M-1],mod-2);
	for(int i=M-2;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	return 1ll*fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	init();
	bool flag=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		flag&=(a[i]<=1);
	}
	if(flag){
		int res=0;
		for(int i=3;i<=n;i++){
			res=(res+C(n,i))%mod;
		}
		cout<<res<<"\n";
	}else{
		int res=0;
		for(int i=1;i<(1<<n);i++){
			int maxv=0,sum=0;
			for(int j=0;j<n;j++){
				if(i>>j&1){
					maxv=max(maxv,a[j]);
					sum+=a[j];
				}
			}
			if(sum>maxv*2){
				res++;
				if(__builtin_expect(res>=mod,0)) res-=mod;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}