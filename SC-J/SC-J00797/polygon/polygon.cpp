#include<bits/stdc++.h>
using namespace std;
const int maxn=5000+10;
const int mod=998244353;
int n,ans=0,maxv=10001,a[maxn],f[maxn],g[maxn*2];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1); g[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=maxv;j++) f[i]=(f[i]+g[j])%mod;
		for(int j=maxv;j>=0;j--) g[min(j+a[i],maxv)]=(g[min(j+a[i],maxv)]+g[j])%mod;
		ans=(ans+f[i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}