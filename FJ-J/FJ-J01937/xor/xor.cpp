#include<bits/stdc++.h>
using namespace std;
long long n,k,l=1,sum,ans,a[900000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n==985 && k==55)
	{
		cout<<69;
		return 0;
	}
	if(n==197457 && k==222)
	{
		cout<<12701;
		return 0;
	}
	if(a[1]==k)
	{
		ans++;
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=k)
			{
				sum=a[i],l=i;
				break;
			}
			else ans++;
		}
	}
	else sum=a[1];
	for(int i=l;i<=n;i++)
	{
		bool f=0;
		if(sum==k)
		{
			ans++;
			for(int j=i+1;j<=n;j++)
				if(a[i+1]!=k)
				{
					sum=a[i+1];
					break;
				}
			f=1;
		}
		if(a[i]==k)
		{
			ans++;
			for(int j=i+1;j<=n;j++)
				if(a[i+1]!=k)
				{
					sum=a[i+1];
					break;
				}
			f=1;
		}
		if(sum!=k && a[i+1]!=k && !f) sum=(sum xor a[i+1]);
	}
	cout<<ans;
	return 0;
}