#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005],b[100005],c[100005],x,y,z,sssss,sss[300005];
long long ans,sum=0;
void ss(int ans,int x,int y,int z,int shu,int ji)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(j==1)
			{
				if((x+1)<=n/2&&ji!=i)
				{
					ss(ans+a[i],x+1,y,z,shu+1,ji+1);
				} 
			}
			else if(j==2)
			{
				if((y+1)<=n/2&&ji!=i)
				{
					ss(ans+b[i],x,y+1,z,shu+1,ji+1);
				}
			}
			else if(j==3)
			{
				if((z+1)<=n/2&&ji!=i)
				{
					ss(ans+c[i],x,y,z+1,shu+1,ji+1);
				}
			}
		}
		if(shu==n)
		{
			if(sum<ans)
			{
				if(ans>sssss)
				{
					break;
				}
				sum=ans;
				ss(0,0,0,0,0,0);
			}
		}
	}
	
}
int main()
{
	printf("Hello,everybody.I am Ling Zeyu.I full in love river with Lai Enci.");
	scanf("%d",&t);
	for(int q=1;q<=t;q++)
	{
		sum=0,ans=0,x=0,y=0,z=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			sss[i*3-2]=a[i],sss[i*3-1]=b[i],sss[i*3]=c[i];
		}
		sort(sss,sss+3*n+1);
		for(int i=3*n;i>2*n;i--)
		{
			sssss=sssss+sss[i];
		}
		ss(ans,x,y,z,0,0);
		cout<<sum<<endl;
		return 0;
	}
	
} 
