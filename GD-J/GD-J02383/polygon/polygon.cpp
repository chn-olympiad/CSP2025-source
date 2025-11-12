#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
    long long a[n]={};
    long long wsy=0;
    
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
	    {
	    	if(i==j)
	    	{
	    		continue;
			}
	    	for(int k=0;k<n;k++)
	        {
	        	if(j==k)
	        	{
	        		continue;
				}
				else if(a[i]+a[j]+a[k]>i||a[i]+a[j]+a[k]>j||a[i]+a[j]+a[k]>k)
				{
					wsy++;
				}
		        
	        }
	    }
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
	    {
	    	if(i==j)
	    	{
	    		continue;
			}
	    	for(int k=0;k<n;k++)
	        {
	        	if(j==k)
	        	{
	        		continue;
				}
				for(int x=0;x<n;x++)
				{
					if(k==x)
	        	    {
	        	    	continue;
				    }
				    else if(a[i]+a[j]+a[k]+a[x]>i||a[i]+a[j]+a[k]+a[x]>j||a[i]+a[j]+a[k]+a[x]>k||a[i]+a[j]+a[k]+a[x]>x)
				    {
				    	wsy++;
				    }
				}
		        
	        }
	    }
	}
	
	cout<<wsy+1;
	return 0;
	
}
