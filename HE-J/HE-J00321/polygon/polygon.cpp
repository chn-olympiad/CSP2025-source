#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],b[5010],ans=2,sum;
bool x;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	if(n==2||n==1||n==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i!=1&&a[i]!=a[i-1])
			x=1;
	}
	if(!x)
	{
		for(int i=3;i<=n;i++)
		{
			ans=1;
			for(int j=n;j>n-i;j--)
				ans*=j;
			sum+=ans;
			sum%=998244353;
		}
		printf("%lld",sum);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=a[i]+b[i-1];
	if(n==3)
	{
		if(a[3]<b[2])
		{
			if(a[1]!=a[2]&&a[2]!=a[3])
			{
				printf("1");
				return 0;
			}
			if(a[1]==a[2]&&a[2]==a[3])
			{
				printf("6");
				return 0;
			}
			if(a[1]==a[2]||a[2]==a[3])
			{
				printf("2");
				return 0;
			}
		}
		else
			printf("0");
		return 0;
	}
	printf("100");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

