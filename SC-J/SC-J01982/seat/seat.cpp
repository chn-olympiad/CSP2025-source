#include<bits/stdc++.h>
using namespace std;
int a[10100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	int c,r,R,sum,h,l=0,sum1;
	cin>>c>>r;
	sum=c*r;
	for(int i=1;i<=c*r;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	for(int i=1;i<=c*r;i++)
	{
		if(R>a[i])sum=sum-1;
	}    
	sum1=sum;
		if(sum<=c)cout<<1<<" "<<sum;	
	    if(sum>c)
	    {
	    	for(int i=1;i<=c;i++)
	    	{
	    		sum1=sum1-c,l++;
	    		if(sum1<=0)
	    		{
	    			if(l%2==0)
	    			{
	    				sum=sum%c;
	    				h=c+1-sum;
	    				cout<<l<<" "<<h;return 0;
					}
					if(l%2==1)
	    			{
	    				h=sum%c;
	    				cout<<l<<" "<<h;return 0;
					}
				}
			}
		}
	return 0;
} 