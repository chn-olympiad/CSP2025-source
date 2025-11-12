#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=5005;
int n;
long long ans;
long long a[N],f[N][N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=0;i<a[1];i++)
		f[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=5000;j++)
			f[i][j]=(f[i][j]+f[i-1][j])%MOD;
		for(int j=0;j<=5000;j++)
			f[i][j]=(f[i][j]+f[i-1][max(j-a[i],0ll)])%MOD;
		for(int j=0;j<a[i];j++)
			f[i][j]=(f[i][j]+1)%MOD;
	}
	for(int i=3;i<=n;i++)
		ans=(ans+f[i-1][a[i]])%MOD;
	printf("%lld",ans);
	return 0;
}
