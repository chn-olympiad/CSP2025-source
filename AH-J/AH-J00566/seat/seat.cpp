#include<bits/stdc++.h>
using namespace std;
long long cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long a[20][20],n,m,s[400],temp=0,f;
	memset(s,0,sizeof(s));
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			a[i][j]=0;
		}
	}
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n*m;i++)
	{
		scanf("%lld",&s[i]);
		if(i==0)
		{
			f=s[i];
		}
	}
	sort(s,s+n*m,cmp);
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<m;j++)
			{
				if(s[temp]==f)
				{
					printf("%lld %lld",i+1,j+1);
					return 0;
				}
				temp++;
			}
		}else{
			for(int j=m-1;j>=0;j--)
			{
				if(s[temp]==f)
				{
					printf("%lld %lld",i+1,j+1);
					return 0;
				}
				temp++;
			}
		}
	}
	
	return 0;
}
