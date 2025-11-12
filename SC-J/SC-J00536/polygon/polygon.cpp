#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	for(int i=0;i<=pow(2,n)-1;i++)
	{ 
		int maxn=INT_MIN;
		long long sum=0,num=0;
		for(int j=1;j<=n;j++)
		{
			if( (i&(1<<(j-1))) > 0)
			{
				maxn=max(maxn,a[n+1-j]);
				sum+=a[n+1-j];
				num++;
			}
			
		}
		if(sum>2*maxn && num>=3)
			ans=((ans%998244353)+1)%998244353;
	}
	cout<<ans;
    return 0;
}