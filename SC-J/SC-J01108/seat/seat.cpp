#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b=0,b1,b2[100],b4=1,b5=1,b3;
	while(scanf("%d",&b1)==1)
	{
		if(b==0)
		{
			n=b1;
		}
		if(b==1)
		{
			m=b1;
		}
		if(b>1)
		{
			b2[b-2]=b1;
		}
		b++;
	}
    for(int i=0;i<b-3;i++)
	{
		b3=b5;
		b5=1;
		for(int k=0;k<i;k++)
    	{
     		if(b2[i]>b2[k])
	    	{
	    		int b3;
	     		b3=b2[b-2];
	       		b2[i]=b2[k];
	     		b2[k]=b3;
	     		b5++;
	     		b4=i;
	    	}
    	}	
	} 
	printf("%d",b4);
	b5==1?printf(" %d",b3):printf(" %d",b5);
    return 0;
 } 