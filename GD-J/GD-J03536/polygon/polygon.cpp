#include<bits/stdc++.h>
using namespace std;
long long int n,a[5006],b[5003],f[5006],ff,zd=1;
bool vis[5006];
void dif(long long int z,long long int d,long long int i,long long u,long long int fff)
{
	if(fff<3)return;
	for(int j=u;j<i;j++)
	{
		if(z-a[j]>d&&fff-1>=3)
		{
			ff++;
			dif(z-a[j],d,i,j+1,fff-1);
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		ff+=n+1;
		for(int i=1;i<=n;i++)
		{
			ff=ff+n-i;
		}
		ff%=998244353;
		cout<<ff;
		for(int i=1;i<=n;i++)
		{
			zd*=2;
			zd%=998244353;
		}
		cout<<zd;
		zd-=ff;
		if(zd<0)zd+=998244353;
		printf("%lld",zd);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
		if(b[i-1]<=a[i]||i<3)continue;
		ff=0;
		dif(b[i-1],a[i],i,1,i);
		zd=zd%998244353+ff%998244353;
	}
	printf("%lld",zd+1);
	return 0;
 } 
