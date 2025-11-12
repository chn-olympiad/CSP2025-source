#include<bits/stdc++.h>
using namespace std;
long long n,k,b=0;
long long sum=0,ans=0;
long long a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			b++;
		}
	}
	if((k==0)&&(b==n))
	{
		cout<<n/2;
		return 0;
	}
	sum=0;
	for(int i=1;i<=n;i++)
	{
		sum=sum^a[i];
		if(sum==k)
		{
			sum=0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
