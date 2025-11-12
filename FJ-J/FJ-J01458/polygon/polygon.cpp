#include <bits/stdc++.h>
using namespace std;
long long a[10000];
long long n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
    sort(a+1,a+n+1);
    long long su=0;
    for(long long i=n;i>=3;i--)
    {
    	for(long long j=2;j<n;j++)
    	{
    		long long cnt=0;
			long long o=1;
    		for(long long l=1;l<=j;l++)
    		{

    			for(long long k=o;k<i;k++)
    			{
    				cnt+=a[k];
    				if(cnt>a[i]*2)
    				{
    					su++;
						break;
					}
				}
				o++;
				
			}
		}
	}
	cout<<su;
	return 0;
}
