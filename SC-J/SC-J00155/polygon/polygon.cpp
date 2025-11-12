#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010,mod=998244353;
int a[N],f[N][N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%lld",&n);
	int mx=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),mx=max(mx,a[i]);
	sort(a+1,a+1+n);
	int ans=0;
	f[0][0]=1;
	int p2=1;
	for(int i=1;i<=n;i++,p2=p2*2%mod){
		for(int j=0;j<=mx;j++){
			f[i][j]=f[i-1][j];
			if(j>=a[i]) (f[i][j]+=f[i-1][j-a[i]])%=mod;
		}
		int sum=0;
		for(int j=0;j<=a[i];j++) (sum+=f[i-1][j])%=mod;
		(ans+=p2-sum+mod)%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}