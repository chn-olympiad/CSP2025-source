#include<bits/stdc++.h>
using namespace std;
int a[5500],v[5500];
int main()
{
	/*freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);*/
	int n,b=1,ans=0,c=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		for(int k=1;k>=1;k++)
		{
			if(i+b<=n+1)
	        {
		        for(int j=b;j<i+b;j++)
		        {
		        	if(v[j+1]==0)
		        	{
		        		 c=c+a[j];
		    		}
		        }
		        if(c>(i+b)*2) ans++;
				v[b+2]=1;
		    }
		    else k=0;
	        b++;
		    for(int j=1;j<=n;j++) v[i]=0;
	    }
	    b=1;	
	}
	cout<<ans;
	return 0;
 } 
