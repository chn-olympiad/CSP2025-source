#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],sum=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	if(k==0)
	{
		if(n%2==0)
		{
			cout<<n/2;
		}
		else
		{
			cout<<n/2+1;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i)
		{
			if(b[j]^b[j-i]==k)
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
