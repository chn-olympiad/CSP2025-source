#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>
using namespace std;
int n,m,a[5005];
long long w_ans,f[5005],g[5005],w_num[5005],C[5005][5005],w_mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		m=max(m,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%w_mod;
	}
	g[0]=1;
	for(int i=1;i<=n;i++)
	{
//		printf("g[]:");
//		for(int j=1;j<=m;j++)
//			printf("%lld ",g[j]);
//		printf("\n");
//		printf("f[%d]=",i);
		for(int j=1;j<i;j++)
//		{
			f[i]=(f[i]+C[i-1][j])%w_mod;
//			printf("C(%d,%d)%lld+",i-1,j,C[i-1][j]);
//		}
//		printf("-%d\n",w_num[a[i]]);
		f[i]=((f[i]-w_num[a[i]])%w_mod+w_mod)%w_mod;
		w_ans=(w_ans+f[i])%w_mod;
		for(int j=m;j>=a[i];j--)
			g[j]=(g[j]+g[j-a[i]])%w_mod;
		for(int j=1;j<=m;j++)
			w_num[j]=(w_num[j-1]+g[j])%w_mod;
	}
	printf("%lld",w_ans);
	return 0;
}
