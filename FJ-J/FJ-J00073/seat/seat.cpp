#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,c,r,num=1;
	cin>>n>>m;
	long long a[n*m+100];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
    for(int i=1,j=1;i<=n*m;i++)
    {
    	if(a[j]<a[i])
    	{
    		num++;
		}
	}
	if(num<m)
	{
		cout<<"1 "<<num;
	}
	else
	{
	    if(num%m==0)
	    {
		   if((num/m)%2==0)
		   {
		   	 c=num/m;
		   	 r=1;
			} 
			else
			{
				c=num/m;
				r=m;
			}
	    }
	    else
	    {
	    	if(num/m%2==0)
	    	{
	    		c=num/m+1;
	    		r=num%m;
			}
			else
			{
				c=num/m+1;
				r=m-(num%m-1);
			}
		}
	}
	cout<<c<<" "<<r;
	
	
	return 0;
}
//2
