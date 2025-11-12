#include<bits/stdc++.h>
#define int long long
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define mod 998244353
using namespace std;
const int N=5e3+30;
int ans=0;
int n;
int a[N];
int A[N];
void init(){
	A[1]=1;
	for(int i=2;i<=5000;i++){
		A[i]=A[i-1]*i%mod;
		A[i]%=mod;
	}
	return ;
}
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1) res*=a;
		a*=a%mod;
		b>>=1;
		res%=mod;
		a%=mod;
	}
	return res;
}
int C(int u,int d){
	if(u>d) return -1;
	return A[d-u]*ksm(A[u],mod-2)%mod*ksm(A[u],mod-2)%mod;
}
signed main(){
	file(polygon);
	init();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		ans+=A[n]%mod*ksm(A[i],mod-2)%mod*ksm(a[i],mod-2)%mod;
		ans%=mod;
//		cout<<ans<<endl;
	}
	cout<<ans%mod<<endl;
}

