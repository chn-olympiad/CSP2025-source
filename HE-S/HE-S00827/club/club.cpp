#include <bits/stdc++.h>
using namespace std;
int t,n,d1[100005],d2[100005],d3[100005],sum[5];
int d1=0,d2=0,d3=0;
int main() 
{
	freopen("club.in ","r",stdin);
	freopen("club.out ","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
	    int c=n/2;
	    for(int j=1;j<=n;j++)
	    { 
		    cin>>d1[j]>>d2[j]>>d3[j];
		    int a=max(d1[j],d2[j],d3[j]);
		    while(a==d1[j] and d1<=n/2)
		    {
			    d1+=1;
		    }
	        while(a==d2[j] and d2<=n/2)
		    {
			    d2+=1;
	 	    }
		    while(a==d3[j] and d3<=n/2)
		    { 
			    d3+=1;
		    }
		    sum[i]=d1[j]*d1+d2[j]*d2+d3[j]*d3;
			cout<<sum[i];
		    
	    }
    }
	return 0;
	
}
