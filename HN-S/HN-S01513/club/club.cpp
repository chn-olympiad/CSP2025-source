#include<bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		int x[4];
		x[0]=0,x[1]=0,x[2]=0,x[3]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
		    {
		    	cin>>a[j];
		    	if(a[j]>a[j-1]&&a[j]>x[i])
		    	{
		    		x[i]=a[j];
				}
		    }
	    }
	    int s=0;
	    for(int i=1;i<=n;i++)
    	    {
	        	s+=x[i];
		     }   
		     cout<<s<<endl;
	}
	return 0;
}

