#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long n,m,a=0,c,g=0,v,i=1;
	long arr[200]={0};
	cin>>n>>m;
	for(c=1;c<=n*m;c++)
	{
		cin>>arr[c];
	}
	v=arr[1];
	a=n*m;
	sort(arr+1,arr+1+a);
	c=1;
	i=1;
		for(a=n*m;a>0;a--)
		{
			if(arr[a]==v)
			{
				cout<<c<<" "<<i;
				return 0;
			}
			if(n!=1)
			{
				if(i<n && g==0)
				{
					i++;
				}
				else if(i==n && g==0)
				{
					g=1;
					c++;
					continue;
				}		
				if(g==1)
				{
					if(i!=1)
					{
					i--;
					}
					else if(i==1)
					{
						g=0;
						c++;				
					}
				}
				
			}
		}
	
				
	return 0;
}
