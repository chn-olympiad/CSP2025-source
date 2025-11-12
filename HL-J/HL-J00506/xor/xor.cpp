#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,k,cnt=0;
    cin>>n>>k;
    long long a[n+1];
    long long cnt1=0,cnt0=0;
    for(long long i=1;i<=n;i++)
    {
    	cin>>a[i];
    	if(a[i]==1) cnt1++;
    	else if(a[i]==0) cnt0++;
	}
	if(k==0)
	{
		if(cnt1==n)
		{
			cout<<n/2;
			return 0;
		}
		if((cnt1+cnt0)==n)
		{
			long long cnt=0;
			for(long long i=1;i<n;i++)
			{
				if(a[i]==1 and a[i+1]==1)
				{
					cnt++;
				    i++;
				}
				else if(a[i]==0) cnt++; 
			}
			cout<<cnt;
		}
	}
	if(k==1)
	{
		long long sum=0;
		for(long long i=1;i<=n;i++)
		{
			if(a[i]==1) sum++;
		}
		cout<<sum;
	}
	return 0;
}