#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5010;
const int mod=998244353;
int a[N];
LL ans,n,fac[N],inv[N],sum[N],v[N];
LL ksm(LL a,LL b){
	LL c=1ll;
	for(;b;b>>=1){
		if(b&1)c=c*a%mod;
		a=a*a%mod; 
	} 
	return c;
}
LL C(LL n,LL m){
	return fac[m]*inv[n]%mod*inv[m-n]%mod;
}
void sub1(){
	for(LL k=3;k<=n;k++){
		ans=(C(k,n)+ans)%mod;
	} 
	cout<<ans;
}
void dfs(int x){
	if(x==n+1){
		int mx=0,s=0;
		for(int i=1;i<=n;i++){
			if(v[i]){
				s+=a[i];
				mx=max(mx,a[i]);
			} 
		}
		if(s>mx*2){
			ans++;
			ans%=mod;
		} 
		return;
	} 
	dfs(x+1);
	v[x]=1;
	dfs(x+1);
	v[x]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	inv[0]=1;
	inv[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=1;i--){
		inv[i]=ksm(fac[i],mod-2);
	}
//	cout<<C(3,5);
	bool subtask1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)subtask1=0; 
	}
	sort(a+1,a+n+1);
	if(subtask1==1){
		sub1();
		return 0;
	}
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<"1";
		else cout<<"0";
		return 0; 
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
/*
21
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
*/
