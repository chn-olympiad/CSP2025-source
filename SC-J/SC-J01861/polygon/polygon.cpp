#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5e3+5;
int n,a[N],ans,qp[N],fac[N];
bool fl=1;
void dfs(int step,int sum,int cnt,int mx){
	if(step==n+1){
		return;
	}
	if(mx!=10000&&sum+a[step]>2*a[mx]){
		ans=(ans+qp[n-step])%mod;
	}
	else{
		dfs(step+1,sum+a[step],cnt+1,min(mx,step));
	}
	dfs(step+1,sum,cnt,mx); 
}
int quick_pow(int a,int b){
	int res=1;
	while(b){
		if(b&1){
			res*=a;
			res%=mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	qp[0]=1;
	fac[0]=1;
	for(int i=1;i<=5000;i++){
		qp[i]=qp[i-1]*2%mod;
		fac[i]=fac[i-1]*i%mod;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			fl=0;
		}
	}
	if(fl==1){
		for(int i=3;i<=n;i++){
			ans=(ans+fac[n]*quick_pow(fac[n-i]*fac[i]%mod,mod-2)%mod)%mod;
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1,greater<int>());
		dfs(1,0,0,10000);
		cout<<ans;
	}
}