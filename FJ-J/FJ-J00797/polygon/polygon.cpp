#include <bits/stdc++.h>
using namespace std;
const int N=5e3,M=1e4,mod=998244353; 
int n,ans,a[N+10],f[M+10],g[M+10];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=M+1;j++)
			(g[min(M+1,j+a[i])]+=f[j])%=mod;
		for(int j=M;j>2*a[i];j--)
			(ans+=g[j])%=mod;
		for(int j=0;j<=M+1;j++)
			(f[j]+=g[j])%=mod,g[j]=0;
	}
	(ans+=f[M+1])%=mod;
	printf("%d",ans);
}
