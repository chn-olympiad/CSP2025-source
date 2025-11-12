#include<bits/stdc++.h>
using namespace std;
long long sum[500005];
long long a[5000005];
int main()
{
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[1]=a[1];
		sum[i+1]=(sum[i-1]^a[i]);
	}
	long long ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<"\n";
//	for(int i=1;i<=n;i++)
//	{
//		cout<<sum[i]<<" ";
//	}
//	cout<<"\n";
	for(int i=1;i<=n;i++)
	{
		if(sum[i]==k)
		{
			ans++;
		}
		if(a[i]==k)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

