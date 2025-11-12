#include<bits/stdc++.h>
#define int long long
const int N=5022,mod=998244353;
//dp??? dfs!!!
using namespace std;
int n,m,a[N],ans,flone,f[N][N];
void dfs(int x,int sum,int ma){
	if(sum>ma*2) ans=(ans+1)%mod;
	for(int i=x+1;i<=n;i++){
		dfs(i,sum+a[i],max(ma,a[i]));
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),flone+=(a[i]==1);
	sort(a+1,a+n+1);
	if(flone==n){
		f[1][1]=1;
		for(int i=2;i<=n+1;i++){
			for(int j=1;j<=i;j++){
				f[i][j]=(f[i-1][j-1]+f[i-1][j])%mod;
			}
		}
		int yyy=0;
		for(int i=1;i<=n-2;i++) yyy=(yyy+f[n+1][i])%mod;
		printf("%lld",yyy);
		return 0;
	}
	dfs(0,0,0);
	printf("%lld",ans);
}
