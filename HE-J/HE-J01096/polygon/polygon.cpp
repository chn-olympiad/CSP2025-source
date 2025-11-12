#include<cstdio>
#include<algorithm>
using namespace std;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n<3) 
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==3)
	{
		int cnt=a[1]+a[2]+a[3];
		int maxn=max(a[1],max(a[2],a[3]));
		if(cnt>2*maxn)
		{
			printf("1");
			return 0;
		}
		else 
		{
			printf("0");
			return 0;
		}
	}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++)
				{
					int sum=a[i]+a[j]+a[z];
					int maxn=max(a[i],max(a[j],a[z]));
					if(sum>maxn*2) cnt++;
				}
			}
		}
		if(n==4)
		{
		  int sum=a[1]+a[2]+a[3]+a[4];
		  int maxn=max(max(a[1],a[2]),max(a[3],a[4]));
		  if(sum>2*maxn) cnt++;
		  printf("%d",cnt);
		  return 0;
	    }
	    for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++)
				{
					for(int i1=z+1;i1<=n;i1++)
					{
					  int sum=a[i]+a[j]+a[z]+a[i1];
					  int maxn=max(max(a[i],a[i1]),max(a[j],a[z]));
					  if(sum>maxn*2) cnt++;
				    }
				}
			}
		}
		if(n==5)
		{
			int sum=a[1]+a[2]+a[3]+a[4]+a[5];
		   int maxn=max(max(max(a[1],a[2]),max(a[3],a[4])),a[5]);
		   if(sum>2*maxn) cnt++;
		   printf("%d",cnt);
		   return 0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++)
				{
					for(int i1=z+1;i1<=n;i1++)
					{
					  for(int i2=i1+1;i2<=n;i2++)
			         {
					  int sum=a[i]+a[j]+a[z]+a[i1]+a[i2];
					  int maxn=max(max(max(a[i],a[j]),max(a[z],a[i1])),a[i2]);
					  if(sum>maxn*2) cnt++;
				     }
				    }
				}
			}
		}
		if(n==6)
		{
			int sum=a[1]+a[2]+a[3]+a[4]+a[5]+a[6];
		   int maxn=max(max(max(max(a[1],a[2]),max(a[3],a[4])),a[5]),a[6]);
		   if(sum>2*maxn) cnt++;
		   printf("%d",cnt);
		   return 0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++)
				{
					for(int i1=z+1;i1<=n;i1++)
					{
					  for(int i2=i1+1;i2<=n;i2++)
			         {
					    for(int i3=i2+1;i3<=n;i3++)
					    {
						 int sum=a[i]+a[j]+a[z]+a[i1]+a[i2]+a[i3];
					     int maxn=max(max(max(max(a[i],a[j]),max(a[z],a[i1])),a[i2]),a[i3]);
					     if(sum>maxn*2) cnt++;
					    }
				     }
				    }
				}
			}
		}
		if(n==7)
		{
			int sum=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7];
		   int maxn=max(max(max(max(max(a[1],a[2]),max(a[3],a[4])),a[5]),a[6]),a[7]);
		   if(sum>2*maxn) cnt++;
		   printf("%d",cnt);
		   return 0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++)
				{
					for(int i1=z+1;i1<=n;i1++)
					{
					  for(int i2=i1+1;i2<=n;i2++)
			         {
					    for(int i3=i2+1;i3<=n;i3++)
					    {
						 for(int i4=i3+1;i4<=n;i++)
						 {
						  int sum=a[i]+a[j]+a[z]+a[i1]+a[i2]+a[i3]+a[i4];
					      int maxn=max(max(max(max(max(a[i],a[j]),max(a[z],a[i1])),a[i2]),a[i3]),a[i4]);
					      if(sum>maxn*2) cnt++;
					     }
					    }
				     }
				    }
				}
			}
		}
		if(n==8)
		{
			int sum=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8];
		   int maxn=max(max(max(max(max(max(a[1],a[2]),max(a[3],a[4])),a[5]),a[6]),a[7]),a[8]);
		   if(sum>2*maxn) cnt++;
		   printf("%d",cnt);
		   return 0;
		}
	return 0;
}
