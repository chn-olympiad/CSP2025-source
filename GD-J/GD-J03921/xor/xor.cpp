#include<bits/stdc++.h>
using namespace std;
long n,k,a[500010],sum1=0,sum2=0,ans=-1,t=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long i=0;i<n;i++)
	{
		for(long j=i;j<n;j++)
		{
			sum1=0;
			for(long l=i;l<=j;l++)
			{
				sum1|=a[l];
			}
			if(sum1==k)
			{
				sum2++;
				i=j+1;
				j=i;
			}
		}
		ans=max(ans,sum2);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
