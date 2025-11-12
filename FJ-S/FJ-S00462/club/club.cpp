#include<bits/stdc++.h>
using namespace std;
const int N=100007;
struct my
{
	int i1,i2,i3;
}myd[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;	
	scanf("%d",&t);
	while(t--)
	{
		int n,sum=0,a=0,b=0,c=0;
		scanf("%d",&n);
		int x=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&myd[i].i1,&myd[i].i2,&myd[i].i3);
			int maxi=max(max(myd[i].i1,myd[i].i2),myd[i].i3);
			if(maxi==myd[i].i1)
			{
				if(a==x)
				{
					int maxj=max(myd[i].i2,myd[i].i3);
					if(maxj==myd[i].i2)
					{
						if(b==x)
						{
							sum+=myd[i].i3;
							c++;
							continue;
						}
						else
						{
							sum+=maxj;
						}
					}
					continue;
				}
				else
				{
					sum+=maxi;
					a++;
				}
			}
			if(maxi==myd[i].i2)
			{
				if(b==x)
				{
					int maxj=max(myd[i].i1,myd[i].i3);
					if(maxj==myd[i].i1)
					{
						if(a==x)
						{
							sum+=myd[i].i3;
							c++;
							continue;
						}
						else
						{
							sum+=maxj;
						}
					}
					continue;
				}
				else
				{
					sum+=maxi;
					b++;
				}
			}
			if(maxi==myd[i].i3)
			{
				if(c==x)
				{
					int maxj=max(myd[i].i1,myd[i].i2);
					if(maxj==myd[i].i1)
					{
						if(a==x)
						{
							sum+=myd[i].i2;
							b++;
							continue;
						}
						else
						{
							sum+=maxj;
						}
					}
					continue;
				}
				else
				{
					sum+=maxi;
					c++;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
