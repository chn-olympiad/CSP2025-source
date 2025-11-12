#include<bits/stdc++.h>
#define N 5005
#define MAX 5005
#define SUM 10005
using namespace std;
const int mod=998244353;
int n,ans,a[N],pre[N],mx[N];
int f[SUM][MAX];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),
		pre[i]=pre[i-1]+a[i],
		mx[i]=max(mx[i-1],a[i]);
	int vlim=mx[n]<<1|1;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=min(pre[i-1],vlim);j>=0;j--)
			for(int k=mx[i-1];k>=0;k--)
				f[min(j+a[i],vlim)][max(k,a[i])]=(f[min(j+a[i],vlim)][max(k,a[i])]+f[j][k])%mod;
	for(int i=1;i<=min(pre[n],vlim);i++)
		for(int j=1;j<=mx[n]&&(j<<1)<i;j++)
			ans=(ans+f[i][j])%mod;
	printf("%d",ans);
	return 0;
}
