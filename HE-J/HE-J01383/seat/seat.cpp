#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,a[105]={0},i=0,j=0,c=0,r=0,x=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
	    cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m);
	for(i=n*m;i>=1;i--)
	{
		if(a[i]==x)
		{
			x=n*m-i+1;
			break;
		}
	}
	for(j=1;j<=m;j++)
	{
		if(j%2!=0)
		{
			for(i=1;i<=n;i++)
			{
				x--;
	            if(x==0)
	            {
	            	c=j;
	            	r=i;
	            	break;
				}
			}
		}
		else
		{
			for(i=n;i>=1;i--)
			{
				x--;
	            if(x==0)
	            {
	            	c=j;
	            	r=i;
	            	break;
				}
			}
		}
	}
	cout<<c<<" "<<r<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
