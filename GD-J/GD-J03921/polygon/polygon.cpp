#include<bits/stdc++.h>
using namespace std;
long n,a[5010],sum=0,maxnum=-1,ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long i=0;i<n;i++)
	{
		for(long j=i;j<n;j++)
		{
			sum=0;
			maxnum=-1;
			for(long l=i;l<=j;l++)
			{
				sum+=a[l];
				maxnum=max(maxnum,a[l]);
			}
			if(j-i+1>=3&&sum>2*maxnum)
			{
				ans++;
				ans%=998244353;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
