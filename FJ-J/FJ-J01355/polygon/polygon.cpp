#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],maxx,ans;
long long ksm(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res*=a,res%=mod;
		a*=a;a%=mod;
		b>>=1; 
	}
	return res;
}
bool fl[5005];
void dfs(long long x,long long deep,long long ma,long long su,long long i_){
	if(deep==x){
		if(su>ma*2) {ans++;ans%=mod;} 
		return ;
	}
	for(long long i=i_+1;i<=n-x+deep+1;i++){
		if(fl[i]) continue;
		fl[i]=1;
		dfs(x,deep+1,max(ma,a[i]),su+a[i],i);
		fl[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++) maxx=max(maxx,a[i]);
	if(n<3) cout<<0;
	if(n==3)cout<<((a[1]+a[2]+a[3])>2*max(a[1],max(a[2],a[3])));
	else if(maxx==1){
		for(long long i=3;i<=n;i++){
			long long res=1;
			for(long long j=1;j<=i;j++){
				res=((res*(n-j+1))%mod*ksm(j,mod-2))%mod;
			}
			ans+=res;ans%=mod;
		}
		cout<<ans;
	}
	else{
		for(long long i=3;i<=n;i++){
			dfs(i,0,0,0,0);
		}
		cout<<ans%mod;
	} 
}
