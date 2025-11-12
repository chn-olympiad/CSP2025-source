#include <bits/stdc++.h> 
using namespace std;
int main()
{
	preopen("in club","r",inclub)
	preopen("out club","w",outclub)
	int t,n,b1=0,b2=0,b3=0,max=0;
	cin>>t>>n; 
	for(int f=1;f<=t;f++)
	{
	    for(int i=1;i<=n;i++)
	    {
		    int a[5],c1,c2,c3;
	  	    for(int i=1;i<=3;i++)
		    {
			    cin>>a[i];
		    }
		    c1=a[1];
		    c2=a[2];
		    c3=a[3];
		    for(int k=1;k<=3;k++)
		    {
			    for(int j=k;j<=3;j++)
			    {
				    if(a[j]>a[j+1])
				    {
					    int x=a[j];
					    a[j]=a[j+1];
					    a[j+1]=x;
				    }
			    }
		    }
		    max+=a[3];
		    if(a[3]==c1)
	        {
	     	    b1++;
		    }
		    if(a[3]==c2)
	        {
	    	    b2++;
		    }
		    if(a[3]==c3)
	        {
	    	    b3++;
		    }
	    }
	    int m=n/2;
		if(b1<=m or b2<=m or b3<=m)
		{
		    cout<<max;
		}
    }
	return 0;
}
