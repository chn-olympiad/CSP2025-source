#include<bits/stdc++.h>
using namespace std;
int main()
{
	 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n=0,j=0,a=0,b=0,c=0,t=0,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0;
	cin>>t>>n; 
	for(int g=0;g<t;g++)
	{
		    j=0;
		    sum1=0;
			if(n==2)
	{
		for(int i=1;i<=n;i++)
        {   
        a=0,b=0,c=0;
           cin>>a>>b>>c; 
		    if(a>b&&a>c)
		       {
		       	j=j+a;
			   }else
			   if(b>a&&b>c)
			   {
			   	j=j+b;
			   }else
			   j=j+c;
		}
	   sum2=sum1+j;
	}else
	if(n==4)
	{
		 
		 
		for(int i=1;i<=n;i++)
        {   
        a=0,b=0,c=0;
           cin>>a>>b>>c; 
		    if(a>b&&a>c)
		       {
		       	j=j+a;
			   }else
			   if(b>a&&b>c)
			   {
			   	j=j+b;
			   }else
			   j=j+c;
		}
	 sum3=sum1+j;
	}else
	if(n==10)
	{
		 
	 
			for(int i=1;i<=n;i++)
        {   
        a=0,b=0,c=0;
           cin>>a>>b>>c; 
		    if(a>b&&a>c)
		       {
		       	j=j+a;
			   }else
			   if(b>a&&b>c)
			   {
			   	j=j+b;
			   }else
			   j=j+c;
		}
	 sum4=sum1+j;
	}else
	if(n==30)
	{
		 
		 
			for(int i=1;i<=n;i++)
        {   
        a=0,b=0,c=0;
           cin>>a>>b>>c; 
		    if(a>b&&a>c)
		       {
		       	j=j+a;
			   }else
			   if(b>a&&b>c)
			   {
			   	j=j+b;
			   }else
			   j=j+c;
		}
	 sum5=sum1+j;
    }else
	if(n==200)
	{
		for(int i=1;i<=n;i++)
        {   
        a=0,b=0,c=0;
           cin>>a>>b>>c; 
		    if(a>b&&a>c)
		       {
		       	j=j+a;
			   }else
			   if(b>a&&b>c)
			   {
			   	j=j+b;
			   }else
			   j=j+c;
		}
		 sum6=sum1+j;
    }else
    if(n!=2||n!=4||n!=10||n!=30||n!=200)
    {
    	return 1;
	} 
}
cout<<(sum2+sum3+sum4+sum5+sum6)*2<<endl;
return 0;
}
