#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxx=-2147483647,b=0,sum=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int f=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		f=0;maxx=-2147483647;
		for(int j=3;j<=n;j++)
	    {
	    	int r=i;
	    	if(r+j>n)continue;
	  	    while(r<=(r+j))
	  	    {
	  	    	f=f+a[r];
	  	     	if(maxx<a[r])maxx=a[r];
	  	    	r++;
		    }
		    if(f>(2*maxx))
			{
				sum++;
				sum=sum%998%244%353;
			}
	    }
	}
	cout<<sum%998%244%353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
