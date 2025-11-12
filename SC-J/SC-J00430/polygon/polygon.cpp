#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005,mod = 998244353;
int n,a[N],pw[N],ans;
int f[2*N],s[N],fg=1;
void work(){
	int cnt=0;
	for(int s=0;s<(1<<n);++s){
		int cc=0,mx=0;
		for(int i=0;i<n;++i){
			if((s>>i)&1) cc+=a[i+1],mx=max(mx,a[i+1]);
		}
		if(cc>2*mx){
			++cnt;
		}
	}
	cout<<cnt<<"\n";
	exit(0);
}
void work2(){
	cout<<((pw[n]-1-n*(n-1)/2%mod-n)%mod+mod)%mod<<"\n";
	exit(0);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	pw[0]=1;
	for(int i=1;i<=n;++i) pw[i]=pw[i-1]*2%mod;
	for(int i=1;i<=n;++i) cin>>a[i],fg&=(a[i]==1);
	stable_sort(a+1,a+n+1);
	if(n<=20) work();
	if(fg) work2();
	f[0]=1;
	s[1]=2;
	for(int i=1;i<=n;++i){
		for(int j=2*a[n];j>=a[i];--j){
			(f[j]+=f[j-a[i]])%=mod;
		}
		for(int j=0;j<=a[i+1];++j) (s[i+1]+=f[j]*2)%=mod;
		for(int j=a[i+1]+1;j<=2*a[i+1];++j) (s[i+1]+=f[j])%=mod;
		if(a[i]!=a[i+1])
			ans+=((pw[i]-s[i])%mod+mod)%mod;
		ans%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}