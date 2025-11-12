#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+10,N=5e3+3,MOD=998244353;
int n,k,a[MAXN];
long long g[MAXN][MAXN],f[MAXN][MAXN],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n),g[0][0]=1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=N;j++){
			g[i][j]=g[i-1][j];
			if(j>=a[i]) g[i][j]=(g[i][j]+g[i-1][j-a[i]])%MOD;
			else g[i][j]=(g[i-1][0]+g[i][j])%MOD;
		}
	}
	for(int i=1;i<=n;i++) ans=(ans+g[i-1][a[i]+1])%MOD;
	printf("%lld",ans);
	return 0;
} 

