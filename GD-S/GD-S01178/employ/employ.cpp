#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,mod=998244353;
int T,n,m,ans;
int a[N],p[N];
int fac[N],inv[N];
char str[N];
bool bj[N];
void dfs(int x){
	if(x==n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(p[i]<=sum){
				sum++;
				continue ;
			}
			else{
				if(str[i]=='0') sum++; 
			}
//			cout<<p[i]<<" ";
		}
//		cout<<endl;
		if(n-sum>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!bj[i]){
			bj[i]=1,p[x+1]=a[i];
			dfs(x+1);
			bj[i]=0,p[x+1]=0;
		}
	}
}
int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1; 
	}
	return res;
}
void init(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=n*n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n*n]=ksm(fac[n*n],mod-2);
	for(int i=n*n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int x,int y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main(){
	freopen("employ3.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	init();
	scanf("%s",str+1);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	int num=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='1') num++;
	}
	if(num==n){
		int cnt=0;
		for(int i=1;i<=n;i++) if(a[i]) cnt++;
		int res=1;
		for(int i=1;i<=cnt;i++) res*=i,res%=mod;
//		cout<<C(n,n-cnt);
		printf("%lld",res*C((n+1)*(n-cnt),cnt)%mod);
	}
	else{
		dfs(0);
		printf("%lld",ans);
	}
	return 0;
}
