#include <bits/stdc++.h>
using namespace std;
long long a[500010];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long cn=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<=n-i;j++)
		{
			long long cnt=a[i+j];
      	    for(long long l=i+j+1;l<=j;l++)
	        { 
	        	cnt+=cnt^a[i];
    	    }
    	    if(cnt==k)
    	    {
    	    	cn++;
    	    	i+=j;
    	    	break;
			}
	        
		}
	}
	cout<<cn;
	return 0;
 } 
