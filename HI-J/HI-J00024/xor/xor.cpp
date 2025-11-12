#include<bits/stdc++.h>
using namespace std;
int n,k;
int a,b,c;
int main ()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&b);
			if(b==1)a++;
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&b);
			if(b==0)
			{
				c=0;a++;
			}
			else
			{
				c=c^b;
				if(c==0)a++;
			}
		}
	}
	printf("%d",a);
	return 0;
}
