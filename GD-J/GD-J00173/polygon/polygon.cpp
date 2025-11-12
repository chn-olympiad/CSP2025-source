#include<cstdio>
#include<algorithm>
using namespace std;
int s[5005],n;
long long c[5001][5001];
int work(int zs)
{
	int sum=0,maxn=-1;
	for(int i=1;i<=n&&zs!=0;i++)
	{
		if(zs&1)
		{
			sum+=s[i];
			maxn=max(maxn,s[i]);
		}
		zs=(zs>>1);
	}
	return sum>maxn*2;
}
long long jc(const int &n)
{
	long long s=1;
	for(int i=2;i<=n;i++)s*=i;
	return s;
}
long long cc(const int &n,const int &m)
{
	if(c[n][m])return c[n][m];
	else if(c[n][n-m])return c[n][m]=c[n][n-m];
	else if(n==m)return c[n][m]=1;
	else if(m==1)return c[n][1]=n;
	else if(m>n)return 0;
	else if(n<=20&&m<=20)return (jc(n)/jc(n-m)/jc(m))%998244353;
	if(n-m<m)return c[n][m]=(cc(n-1,n-m-1)+cc(n-1,n-m))%998244353;
	return c[n][m]=(cc(n-1,m-1)+cc(n-1,m))%998244353;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	std::sort(s+1,s+1+n);
	if(n<=3)
	{
		if(s[1]+s[2]>s[3])printf("1");
		else printf("0");
	}
	else if(n<=20)
	{
		int ans=0;
		int maxzs=pow(2,n)-1;
		for(int zs=7;zs<=maxzs;zs++)ans+=work(zs);
		printf("%d",ans);
	}
	else
	{
		long long ans=0;
		for(int i=3;i<=n;i++)ans=(ans+cc(n,i))%998244353;
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
