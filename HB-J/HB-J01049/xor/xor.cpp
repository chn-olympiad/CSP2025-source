#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int k,n,m,x[500005][2],y,s,last;
long long i,j,l;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			for(l=i;l<=j;l++)
			{
				m=(a[i]^a[j]);
				if(m==k)
				{
					y++;
					x[y][0]=i;
					x[y][0]=j;
					s=1;
				}
			}
		}
	}
	if(s==0)
	{
		cout<<0;
		return 0;
	}
	for(i=1;i<y;i++)
	{
		for(int j=i+1;j<=y;j++)
		{
			if(x[i][0]>x[j][0] || (x[i][0]==x[j][0] && x[i][1]>x[j][1]))
			{
				swap(x[i],x[j]);
			}
		}
	}
	last=x[1][0];
	for(i=2;i<=y;i++)
	{
		if(x[i][0]!=last)
		{
			s=s+1;
			last=x[i][0];
		}
	}
	cout<<s;
	return 0;
}
