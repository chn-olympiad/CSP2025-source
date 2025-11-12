#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000005
#define mod 998244353
int n,m,j,k,l;
int vis[N];
int sum[N],ans,x[N];
int ll[N];//1-k½×³Ë 
int rr[N];//n-k½×³Ë 
void dfs(int s,int t,int sum,int ho){
	if(s==t&&ho>=3){
		if(sum>x[t]*2){
			ans++;
		}
		return ;
	}
	for(int i=s+1;i<=t;i++){
		dfs(i,t,sum+x[i],ho+1);
		if(i!=t)dfs(i,t,sum,ho);
	}
}
int pp(int a,int b){
	int jj=a;
	int dd=1;
	while(b){
		if(b&1){
			dd=dd*jj%mod;
		}
		jj=jj*jj%mod;
		b>>=1;
	}
	return dd;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		sum[i]=sum[i-1]+x[i];
	}
	sort(x+1,x+1+n);
	if(sum[n]==n){
		ll[1]=1;
		rr[n]=n;
		for(int i=2;i<=n;i++){
			ll[i]=ll[i-1]*i%mod;
		}
		for(int i=n-1;i>=1;i--){
			rr[i]=i*rr[i+1]%mod;
		}
		for(int i=3;i<=n;i++){
			int h=rr[n-i+1]*pp(ll[i],mod-2)%mod;
			ans+=h;
			ans%=mod;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,0,0);
	}
	printf("%lld",ans/2);
	return 0;
} 



