#include<bits/stdc++.h>
using namespace std;
int a[120],b[20][20];
int main()
{
/*	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);*/
	int n,m,c=0,e=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int d=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
	    if(c==0)
	    {
	    	for(int j=1;j<=n;j++)
	        {
	        	if(a[e]==d) 
	        	{
	        		cout<<i<<" "<<j;
	        		return 0;
				}
			    b[i][j]=a[e];
			    e++;
		    }
		    c=1;
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				if(a[e]==d)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				b[i][j]=a[e];
				e++;
			}
			c=0;
		}
	
	}
 } 
