#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=5005;
const int mod=998244353;
int a[maxn],f[maxn],u[maxn],n,mx,ans;
void dfs(int m,int sum,int mx){
	if(m>=4 && (sum>(mx<<1))){
		ans++;
	}
	if(m>n){
		return;
	}
	for(int i=f[m-1]+1;i<=n;i++){
		if(!u[i]){
			f[m]=i;
			u[i]=1;
			dfs(m+1,sum+a[i],max(mx,a[i]));
			u[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	if(mx==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans<<=1;
			ans%=mod;
		}
		printf("%lld",(ans-1-n-(n*(n-1)/2)+mod)%mod);
		return 0;
	}
	dfs(1,0,0);
	printf("%lld",ans%mod);
	return 0;
}
