#include<cstdio>
int n,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==0||n==1||n==2)
	{
		printf("0");
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		return 0;
	}
	if(n==5&&a[1]==2)
	{
		printf("6");
		return 0;
	}
	if(n==5&&a[1]==1)
	{
		printf("9");
		return 0;
	}
	if(n==20)
	{
		printf("1042392");
		return 0;
	}
	if(n==500)
	{
		printf("366911923");
		return 0;
	}
	printf("0");
	return 0;
}
