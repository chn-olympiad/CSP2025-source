#include<iostream>
using namespace std;
long long n,a[20005][4],i,ma,ans[20005],b1,b2,b3;
void fs(long long x,int y)
{
	if(y==1)
	{
		b1++;
		if(b1>n/2)
		{
			return ;
		}
	}
	else if(y==2)
	{
		b2++;
		if(b2>n/2)
		{
			return ;
		}
	}
	else if(y==3)
	{
		b3++;
		if(b3>n/2)
		{
			return ;
		}
	}
	if(x==n)
	{
		ma=max(ma,ans[x]);
		return ;
	}
	ans[x+1]=ans[x]+a[x][y-1];
	fs(x+1,1);
	b1--;
	fs(x+1,2);
	b2--;
	fs(x+1,3);
	b3--;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		fs(0,1);
		b1--;
		fs(0,2);
		b2--;
		fs(0,3);
		b3--;
		printf("%lld\n",ma);
		ma=0;
		b1=0;
		b2=0;
		b3=0;
	}
	return 0;
}
