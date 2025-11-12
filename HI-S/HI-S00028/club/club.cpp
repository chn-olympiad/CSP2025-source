#include<bits/stdc++.h>
using namespace std;
int n[200];
int m1[200];
int m2[200];
int m3[200];
int b[200];
int main()
{
freopen("club.in","r",std.in);	
freopen("club.out","w",std.out);
	int t,a;
	cin>>t;
	int c=0;
	int d=0;
	int e=0;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i];
			for(int j=1;j<=n[i];j++)
		   {
			cin>>m1[j]>>m2[j]>>m3[j];
         	   	if(m1[j]>m2[j]&&m1[j]>m3[j])
         	   {
         	   	b[j]=m1[j];
         	   	c++;
			   }
			   if(m2[j]>m1[j]&&m2[j]>m3[j])
         	   {
         	   	b[j]=m2[j];
         	   	d++;
			   }
			   if(m3[j]>m2[j]&&m3[j]>m1[j])
         	   {
         	   	b[j]=m3[j];
         	   	e++;
			   } 
			  
			  }
			  if(c>n[i]/2)
			   {
			   	for(int j=2;j<=n[i];j++)
			   	{
			   		if(m1[j]>m1[j-1])
			   		{
			   			b[j]=m1[j];
					   }
					   else
					   {
					   	if(m1[j]>m2[j]&&m1[j]>m3[j])
         	   {
         	   	b[j]=m1[j];
         	   	c++;
			   }
			   if(m2[j]>m1[j]&&m2[j]>m3[j])
         	   {
         	   	b[j]=m2[j];
         	   	d++;
			   }
			   if(m3[j]>m2[j]&&m3[j]>m1[j])
         	   {
         	   	b[j]=m3[j];
         	   	e++;
			   } 
				   }
				 }
			   		
			   	
			    }
					if(d>n[i]/2)
			   {
			   	for(int j=2;j<=n[i];j++)
			   	{
			   		if(m2[j]>m2[j-1])
			   		{
			   			b[j]=m2[j];
					   }
			if(m1[j]>m2[j]&&m1[j]>m3[j])
         	   {
         	   	b[j]=m1[j];
         	   	c++;
			   }
			   if(m2[j]>m1[j]&&m2[j]>m3[j])
         	   {
         	   	b[j]=m2[j];
         	   	d++;
			   }
			   if(m3[j]>m2[j]&&m3[j]>m1[j])
         	   {
         	   	b[j]=m3[j];
         	   	e++;
			   } 
			        }
				}
			   	
					if(e>n[i]/2)
			   {
			   	for(int j=2;j<=n[i];j++)
			   	{
			   		if(m3[j]>m3[j-1])
			   		{
			   			b[j]=m3[j];
					   }
					   else
					   {
					   		if(m1[j]>m2[j]&&m1[j]>m3[j])
         	   {
         	   	b[j]=m1[j];
         	   	c++;
			   }
			   if(m2[j]>m1[j]&&m2[j]>m3[j])
         	   {
         	   	b[j]=m2[j];
         	   	d++;
			   }
			   if(m3[j]>m2[j]&&m3[j]>m1[j])
         	   {
         	   	b[j]=m3[j];
         	   	e++;
			   } 
					   }
				 }	   	
			}
			c=0;
			d=0;
			e=0;
			}
    }  
	 for(int j=1;j<=n[i];j++)
			{
					a=a+b[j];
		cout<<a<<endl;	
		 return 0;
}
