#include<cstdio>
#include<algorithm>
int n,m,a[105],k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i)
	{
		scanf("%d",&a[i]);
	}
	k=a[1];
	std::sort(a+1,a+1+n*m,[](int x,int y){return x>y;});
	if(n==1)
	{
		for(int i=1;i<=m;++i)
		{
			if(a[i]==k)
			{
				printf("%d 1",i);
				return 0;
			}
		}
	}
	for(int i=1,c=1,r=1,d=1;i<=n*m;++i)
	{
		if(a[i]==k)
		{
			printf("%d %d",c,r);
			return 0;
		}
		if(r==n)
		{
			++c;
			++i;
			if(a[i]==k)
			{
				printf("%d %d",c,r);
				return 0;
			}
			d=-1;
		}
		else if(r==1&&c!=1)
		{
			++c;
			++i;
			if(a[i]==k)
			{
				printf("%d %d",c,r);
				return 0;
			}
			d=1;
		}
		r+=d;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}