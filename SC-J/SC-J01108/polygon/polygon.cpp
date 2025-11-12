#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0,d=0,d1,d2[100],d3=0,d5,d6=0;
	while(scanf("%d",&d1)==1&&n>=d)
	{
		if(d>=1)
		{
			d2[d-1]=d1;
		}
		else
		{
			n=d1;
		}
		d++;
	}
	for(int i=0;i<d-1;i++)
	{
		d6=0;
		for(int k=d-1;k>=i;k--)
		{
			d5=d2[k];
			for(int j=i;j<=k;j++)
			{
				if(d5<d2[j])
		    	{
		     		d6+=d5;
		    		d5=d2[j];
		    	}
		    	else
		    	{
		    		d6+=d2[j];
				}
			}
			if(d5<d6*2)
			{
				d3++;
			}
			if(k==4)
			{
				k=i-1;
			}
		}
	}
	printf("%d",d3);
	return 0;
 }