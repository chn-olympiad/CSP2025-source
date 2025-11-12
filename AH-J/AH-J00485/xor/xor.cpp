#include<bits/stdc++.h>
using namespace std;
int main()//rp++ 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,k;
	cin>>n>>k;
	long long a[n+1],b[n+1]={0},cnt=0;
	bool flag[n+1]={0};
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			cnt++;
			flag[i]=1;
		}
		if(i==1)
		{
			b[i]=a[i];
		}
		else
		{
			b[i]=b[i-1]^a[i];
		}
	}
	for(long long i=1;i<n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			bool f=0;
			for(long long l=i;l<=j;l++)
			{
				if(flag[l]==1)
				{
					f=1;
					break;
				}
			}
			if(f==0)
			{
				if((b[j]^b[i-1])==k)
				{
					cnt++;
					fill(flag+i,flag+j+1,1);
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
