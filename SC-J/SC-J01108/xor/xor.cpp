#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n1,m1,c=0,c1,c2[1000],c3=0,c4[1000];
	while(scanf("%d",&c1)==1)
	{
		if(c==0)
		{
			n1=c1;
		}
		if(c==1)
		{
			m1=c1;
		}
		if(c>1)
		{
			c2[c-2]=c1;
		}
		c++;
	}
	for(int i=0;i<c-2;i++)
	{
		c4[i]=c2[i];
		if(c4[i]==m1)
		{
			c3++;
		}
		else
		{
			for(int k=c-2;k>0;k--)
	     	{
	     		if((c2[i]+c2[k])<=m1)
	     		{
		     		if((c2[i]+c2[k])==m1)
		     		{
		     			c3++;
			    	}
			     	else
			    	{
			    		c2[i]+=c2[k];
		     		}
		      	}
	    	}
		}
	}
	printf("%d",c3);
	return 0;
 } 