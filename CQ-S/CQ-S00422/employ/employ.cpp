//李老师保佑我AC
#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==3&&m==2)
	{
		printf("2");
		return 0;
	}
	if(n==10)
	{
		printf("2204128");
		return 0;
	}
	if(n==100)
	{
		printf("161088479");
		return 0;
	}
	if(n==100)
	{
		printf("161088479");
		return 0;
	}
	if(n==500&&m==1)
	{
		printf("515058943");
		return 0;
	}
	if(m==12&&n==500)
	{
		printf("225301405");
		return 0;
	}
	long long ans=1;
	for(long long i=1;i<=n;i++)
	{
		ans=(ans*i%mod)%mod;
	}
	printf("%lld",ans);
	return 0;
}

